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

void Smiley::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(mouth);
    return;
}

void Sad::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(mouth);
    return;
}

void Surprised::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(mouth);
    win.attach(lBrow);
    win.attach(rBrow);
    return;
}

void Angry::attach_to(Graph_lib::Window& win){
    Sad::attach_to(win);
    win.attach(lBrow);
    win.attach(rBrow);
    return;
}

void Wink::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(rEye);
    win.attach(lEye);
    win.attach(innerL);
    return;
}

void SmileWink::attach_to(Graph_lib::Window& win){
    Wink::attach_to(win);
    win.attach(mouth);
    return;
}

void showEmoji(Vector_ref<Emoji>& emojis, Graph_lib::Window& win){
    for (int i {0}; i < emojis.size(); ++i){
        emojis[i].attach_to(win);
    }
    return;
}