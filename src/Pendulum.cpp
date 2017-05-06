#include "Pendulum.h"

Pendulum::Pendulum()
{
	amplitude = 10;
	frequency = 1;
	phase = 0;
	damping = 1;
}

Pendulum::Pendulum(Vector2f const& _sliderPosition, Font *_font, RenderWindow *_window)
{
	font = _font;

	sliderPosition = _sliderPosition;

	ampSlider = Slider(Vector2f(100,2), Vector2f(2,4), sliderPosition+Vector2f(0,0), 0, 400, "Amplitude: ", *font);
	freqSlider = Slider(Vector2f(100,2), Vector2f(2,4), sliderPosition+Vector2f(0,30), 0, 40, "Frequency: ", *font);
	phaseSlider = Slider(Vector2f(100,2), Vector2f(2,4), sliderPosition+Vector2f(0,60), 0, 360, "Phase: ", *font);
	dampSlider = Slider(Vector2f(100,2), Vector2f(2,4), sliderPosition+Vector2f(0,90), 0, 0.5, "Damping: ", *font);

	amplitude = ampSlider.getSliderValue();
	frequency = freqSlider.getSliderValue();
	phase = phaseSlider.getSliderValue();
	damping = dampSlider.getSliderValue();

	window = _window;
}

float Pendulum::getPosition(float const& t)
{
	return amplitude * sin(t * frequency + phase * PI / 180.f) * exp(-damping * t);
}

void Pendulum::draw()
{
	Vector2f mousePos(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y);

	ampSlider.isSliderClicked(window);
	freqSlider.isSliderClicked(window);
	phaseSlider.isSliderClicked(window);
	dampSlider.isSliderClicked(window);

	amplitude = ampSlider.getSliderValue();
	frequency = freqSlider.getSliderValue();
	phase = phaseSlider.getSliderValue();
	damping = dampSlider.getSliderValue();

	ampSlider.draw(*window);
	freqSlider.draw(*window);
	phaseSlider.draw(*window);
	dampSlider.draw(*window);
}
