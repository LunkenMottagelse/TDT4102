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

	EmptyFace tes1 {Point{200, 200}, emojiRadius, eyeRadius, eyeH, eyeW};
	Smiley tes2 {Point{400, 200}, emojiRadius, eyeRadius, eyeH, eyeW};
	Sad tes3 {Point{600, 200}, emojiRadius, eyeRadius, eyeH, eyeW};
	Surprised tes4 {Point{200, 400}, emojiRadius, eyeRadius, eyeH, eyeW};
	Angry tes5 {Point{400, 400}, emojiRadius, eyeRadius, eyeH, eyeW};
	SmileWink tes6 {Point{600, 400}, emojiRadius, eyeRadius, eyeH, eyeW};

	Vector_ref<Emoji> emojis;

	emojis.push_back(tes1);
	emojis.push_back(tes2);
	emojis.push_back(tes3);
	emojis.push_back(tes4);
	emojis.push_back(tes5);
	emojis.push_back(tes6);

	showEmoji(emojis, win);

	win.wait_for_button();

}

