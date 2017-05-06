#pragma once

#include <SFML/Graphics.hpp>
#include "Slider.h"

using namespace std;
using namespace sf;

const double PI = 3.1415;

class Pendulum
{
public:
	Pendulum() ;
	Pendulum(Vector2f const& _sliderPosition, Font *_font, RenderWindow *_window);

	float getPosition(float const& t);

	void draw() ;

private:
	float amplitude;
	float frequency;
	float phase;
	float damping;

	Vector2f sliderPosition;
	Font *font;
	Slider ampSlider;
	Slider freqSlider;
	Slider phaseSlider;
	Slider dampSlider;

	RenderWindow *window;
};

