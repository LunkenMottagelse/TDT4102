#pragma once
#include "Window.h"
#include "Tile.h"
#include <random>

using namespace Graph_lib;
enum class MouseButton { left = FL_LEFT_MOUSE, right = FL_RIGHT_MOUSE }; //


// Minesweeper GUI
class MinesweeperWindow : public Graph_lib::Window
{
public:
	//storrelsen til hver rute
	static constexpr int cellSize = 30;
	MinesweeperWindow(Point xy, int width, int height, int mines, const string& title);
private:

	const int width;//width i miner 
	const int height;//heigth i miner
	const int mines;//Antall miner
	bool lost = false;
	Vector_ref<Tile> tiles; // Vektor som inneholder alle tiles
	Out_box result;
	Out_box remainingMines;
	int flaggedTiles = 0;
	int openedTiles = 0;
	Button quitBtn;
	Button restartBtn;

	//Height og Width i piksler
	int Height() const { return height * cellSize; }
	int Width() const { return width * cellSize; }

	// Tap eller seier
	void winStatus(bool win);

	// Faa en liste med naborutene rundt en tile
	vector<Point> adjacentPoints(Point xy) const;
	//tell miner basert paa liste
	int countMines(vector<Point> coords) const;

	//Sjekk at punkt er paa brettet og gjor det til Tile
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x < Width() && xy.y >= 0 && xy.y < Height(); }
	Tile& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const Tile& at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

	//aapne og flagge rute
	void openTile(Point xy);
	void flagTile(Point xy);

	//callback funksjon for tile knappen
	static void cb_click(Address, Address pw);
	static void cb_restart(Address, Address pw);
	static void cb_quit(Address, Address pw);
	void restart();
};
