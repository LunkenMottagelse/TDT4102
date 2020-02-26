#include "Emoji.h"
#include "std_lib_facilities.h"

void Face::attach_to(Graph_lib::Window& win){
    win.attach(face);
    return;
}

void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(rEye);
    win.attach(lEye);
    win.attach(innerL);
    win.attach(innerR);
    return;
}