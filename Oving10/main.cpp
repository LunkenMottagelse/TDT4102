#ifdef _WIN32  
#include <Windows.h>
#endif

#include "Tile.h"
#include "MinesweeperWindow.h"
#include <random>


int main()
{

	#ifdef _WIN32
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252); 
	#endif
	srand(time(nullptr));

	Fl::background(200, 200, 200);
	constexpr int width = 10;
	constexpr int height = 10;
	constexpr int mines = 10;

	Point startPoint{ 200,300 };
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	gui_main();
	return 0;

}

