#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};


class Face : public Emoji{
	Graph_lib::Circle face;
public:
	virtual void attach_to(Graph_lib::Window& win) override;

	Face(Point c, int r): face{c, r} {
		face.set_fill_color(Graph_lib::Color::yellow);
	}

	virtual ~Face() {}
};

class EmptyFace :public Face{
	Graph_lib::Circle rEye;
	Graph_lib::Circle lEye;
	Graph_lib::Circle innerR;
	Graph_lib::Circle innerL;
public:
	virtual void attach_to(Graph_lib::Window& win) override;
	EmptyFace(Point center, int rad, int eyeRad, int eyeHeight, int eyeWidth) : Face {center, rad}, rEye{{center.x + eyeWidth, center.y - eyeHeight}, eyeRad}, 
			lEye{{center.x - eyeWidth, center.y - eyeHeight}, eyeRad}, innerR{{center.x + eyeWidth, center.y - eyeHeight}, eyeRad / 2}, 
			innerL{{center.x - eyeWidth, center.y - eyeHeight}, eyeRad / 2} {
		rEye.set_fill_color(Color::white);
		lEye.set_fill_color(Color::white);
		innerL.set_fill_color(Color::black);
		innerR.set_fill_color(Color::black);
	}
};