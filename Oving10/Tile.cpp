#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{ {1, Color::blue},
								   {2, Color::red},
								   {3,Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow} };

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{ {Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"} };

Tile::Tile(Point pos, int size, Graph_lib::Callback cb, bool mine)
		:Button{pos, size, size, "", cb}, isMine{mine} {};

void Tile::open()
{
	if (state != Cell::flagged){
		static_cast<Fl_Button*>(pw)->set();//Setter en button som trykket paa, tilsvarer aapnet rute
		state = Cell::open;
		if (isMine){
			set_label("X");
			set_label_color(Color::red);
		}
	}
	
	return;
}

void Tile::flag()
{
	if (state == Cell::flagged){
		state = Cell::closed;
		set_label(cellToSymbol.at(state));
	}
	else {
		state = Cell::flagged;
		set_label_color(Color::blue);
		set_label(cellToSymbol.at(state));
	}
	return;
}

void Tile::setMineStatus(bool status){
	isMine = status;
	return;
}

bool Tile::getMineStatus() const{
	return isMine;
}

void Tile::setAdjMines(int n){
	set_label(to_string(n));
	set_label_color(minesToColor.at(n));
	return;
}