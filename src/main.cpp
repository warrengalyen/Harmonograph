/**
 *  @file    main.cpp
 *  @author  Warren Galyen
 *  @date    10/25/2015
 *  @version 1.0
 *
 *  @brief Simulates a harmonogram plotter
 *
 *  @section DESCRIPTION
 *
 *  A harmonograph is a device made out of 2 or more pendulums
 *  that drive a pen or a sheet of paper in a given direction.
 *
 *  Given an amplitude (A), a frequency (f), a phase (p) and a
 *  damping coefficient (d) for each pendulum, a pattern is drawn
 *  on the canvas. You can change the 4 coefficients thanks to
 *  sliders on the window, and the curve is updated in real time.
 *  NOTE: When the frequencies are multiples you can obtain
 *        interesting and diverse patterns.
 *
 */

#include <SFML/Graphics.hpp>
#include "Harmonograph.h"
#include "Slider.h"

using namespace std ;
using namespace sf ;

int main()
{
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 800;
    const int WINDOW_COLORDEPTH = 32;
    const int GRAPH_HEIGHT = 500;
    const int GRAPH_WIDTH = 400;
    const int AA_LEVEL = 8;

	ContextSettings aa;
	aa.antialiasingLevel = AA_LEVEL;
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_COLORDEPTH), "Harmonograph", Style::Default, aa);

	Font consolas ; consolas.loadFromFile("consola.ttf");
	Harmonograph graph(Vector2f(GRAPH_WIDTH, GRAPH_HEIGHT), &consolas, &window) ;

	Vector2f mousePos;
	Event event;

	while (window.isOpen())
	{
		while(window.pollEvent(event)) {}

		mousePos = Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

		graph.update() ;

		window.clear(Color::White);
		graph.draw();
		window.display();
	}
}
