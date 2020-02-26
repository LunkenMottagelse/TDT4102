#ifdef _WIN32  
#include <Windows.h>
#endif

#include "std_lib_facilities.h"
#include "animal.h"
#include "Emoji.h"
#include "Simple_window.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;
constexpr int eyeRadius = 10;
constexpr int eyeH = 15;
constexpr int eyeW = 20;


int main()
{

	#ifdef _WIN32
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252); 
	#endif
	
	//testAnimal();

	using namespace Graph_lib;

	const Point tl{500, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	Point emojiPos {200, 200};
	EmptyFace test {emojiPos, emojiRadius, eyeRadius, eyeH, eyeW};
	test.attach_to(win);

	win.wait_for_button();


	keep_window_open();
}

