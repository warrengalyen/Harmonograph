#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include "Utility.h"

using namespace std;
using namespace sf;

class Slider
{
public:
	Slider() ;
	Slider(Vector2f bodySize, Vector2f sliderSize, Vector2f _position, float _min, float _max, string _text, Font &font);

	bool isSliderClicked(RenderWindow *window);
	float getSliderValue();

	void draw(RenderWindow &window);

private:
	RectangleShape body;
	RectangleShape slider;

	Vector2f position;
	Vector2f textPosition;
	Vector2f mousePos;
	Vector2f prevMousePos;

	bool edit;
	bool flag;

	float min;
	float max;

	Text text;
	string initialText;
};

