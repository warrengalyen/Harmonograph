#include "Harmonograph.h"

Harmonograph::Harmonograph(Vector2f const& _position, Font *_font, RenderWindow *_window)
{
	font = _font ;
	window = _window ;

	penX = Pendulum(Vector2f(10,10), font, window) ; //A, f, p, d, t
	penY = Pendulum(Vector2f(210,10), font, window) ; //A, f, p, d, t
	paperX = Pendulum(Vector2f(410,10), font, window) ; //A, f, p, d, t
	paperY = Pendulum(Vector2f(610,10), font, window) ; //A, f, p, d, t

	position = _position ;

	VA.setPrimitiveType(LinesStrip) ;

	tslider = Slider(Vector2f(100,2), Vector2f(2,4), Vector2f(10,700), 0, 100, "t : ", *font) ;
	dtslider = Slider(Vector2f(100,2), Vector2f(2,4), Vector2f(10,730), 0.001, 0.03, "dt : ", *font) ;
	t = tslider.getSliderValue() ;
	dt = dtslider.getSliderValue() ;
}

void Harmonograph::update()
{
	Vector2f mousePos(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y) ;

	tslider.isSliderClicked(window) ;
	dtslider.isSliderClicked(window) ;
	t = tslider.getSliderValue() ;
	dt = dtslider.getSliderValue() ;

	VA.clear() ;
	
	for(float t0(0) ; t0<t ; t0+=dt)
	{
		pen = Vector2f(penX.getPosition(t0), penY.getPosition(t0)) ;
		paper = Vector2f(paperX.getPosition(t0), paperY.getPosition(t0)) ;

		VA.append(Vertex(pen+paper+position, Color::Black)) ;
	}
}

void Harmonograph::draw()
{
	window->draw(VA) ;

	penX.draw() ;
	penY.draw() ;
	paperX.draw() ;
	paperY.draw() ;
	tslider.draw(*window) ;
	dtslider.draw(*window) ;
}

