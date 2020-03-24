#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize + 30, title}, width{width}, height{height}, mines{mines},
	result{Point{0, height*cellSize}, width*cellSize / 2, 30, ""}, remainingMines{Point{width*cellSize/2, height*cellSize}, 
	width*cellSize / 2, 30, ""}, restartBtn{Point{0, 0}, width*cellSize / 2, 40, "Restart", cb_restart}, 
	quitBtn{Point{width*cellSize/2, 0}, width*cellSize / 2, 40, "Quit", cb_quit}
	//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen
{
	// Legg til alle tiles paa vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}
	attach(result);
	attach(remainingMines);
	remainingMines.put(mines);
	attach(quitBtn);
	attach(restartBtn);
	quitBtn.hide();
	restartBtn.hide();

	//Legg til miner paa tilfeldige posisjoner
	vector<int> mineLoc (mines);
	int newNum;
	bool isNew;
	for (int i {0}; i < mines; ++i){
		do{
			isNew = true;
			newNum = rand() % (height * width);
			for (int j : mineLoc){
				if (newNum == j) {
					isNew = false;
					break;
				}
			}
		} while (!isNew);
		mineLoc.push_back(newNum);
		tiles[newNum].setMineStatus(true);
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int mineCount {0};
	for (Point p : points){
		if (at(p).getMineStatus()) ++mineCount;
	}
	return mineCount;
};

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::winStatus(bool win){
	if (!win){
		result.put("You lost!");
		lost = true;
		for(Tile* p : tiles){
			if (p->getMineStatus()) p->open();
		}
	}
	else if (!lost){
		result.put("You won!");
		for(Tile* p : tiles){
			if (p->getMineStatus() && p->getState() != Cell::flagged) p->flag();
		}
	}
	restartBtn.show();
	quitBtn.show();
}

void MinesweeperWindow::openTile(Point xy) {
	if (at(xy).getState() == Cell::closed){
		at(xy).open();
		if (at(xy).getMineStatus()){ 
			winStatus(false);
			return;
		}
		else ++openedTiles;
		if (openedTiles == width*height - mines){
			winStatus(true);
		}

		int adjMines {countMines(adjacentPoints(xy))};
		if (adjMines > 0){
			at(xy).setAdjMines(adjMines);
		}
		else {
			for (Point p : adjacentPoints(xy)){
				openTile(p);
			}
		}
	}
	return;
}

void MinesweeperWindow::flagTile(Point xy) {
	if (at(xy).getState() == Cell::flagged){
		at(xy).flag();
		--flaggedTiles;
	}
	else if (at(xy).getState() == Cell::closed){
		at(xy).flag();
		++flaggedTiles;
	}
	
	remainingMines.put(mines - flaggedTiles);

	return;
}


//Kaller opentile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}

void MinesweeperWindow::cb_quit(Address, Address pw){
	reference_to<MinesweeperWindow>(pw).hide();
	return;
}

void MinesweeperWindow::cb_restart(Address, Address pw){
	reference_to<MinesweeperWindow>(pw).hide();
	reference_to<MinesweeperWindow>(pw).restart();
	
	return;
}

void MinesweeperWindow::restart(){
	MinesweeperWindow mw {Point{200, 300}, this->width, this->height, this->mines, ""};
	gui_main();
	return;
}