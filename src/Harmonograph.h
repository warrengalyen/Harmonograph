#pragma once

#include <SFML/Graphics.hpp>
#include "Pendulum.h"
#include <iostream>

using namespace std ;
using namespace sf ;

class Harmonograph
{
public:
	Harmonograph(Vector2f const& _position, Font *_font, RenderWindow *_window) ;

	void update() ;
	
	void draw() ;

private:
	Pendulum penX ;
	Pendulum penY ;
	Pendulum paperX ;
	Pendulum paperY ;

	Vector2f pen ;
	Vector2f paper ;
	Vector2f position ;
	float t ;
	float dt ;
	Slider tslider ;
	Slider dtslider ;

	Font *font ;
	RenderWindow *window ;
	VertexArray VA ;
};

