#include "Slider.h"

using namespace std;
using namespace sf;

Slider::Slider()
{
}

Slider::Slider(Vector2f bodySize, Vector2f sliderSize, Vector2f _position, float _min, float _max, string _text, Font &font)
{
    body = RectangleShape(bodySize);
    slider = RectangleShape(sliderSize);
    body.setFillColor(Color::Blue);
    body.setOutlineColor(Color::Black);
    body.setOutlineThickness(1);
    slider.setFillColor(Color::White);
    slider.setOutlineColor(Color::Black);
    slider.setOutlineThickness(1);

    textPosition = _position;
    text.setFont(font);
    text.setPosition(_position);
    text.setCharacterSize(13);
    text.setString(_text);
    text.setFillColor(Color::Black);
    initialText = _text;

    position = _position + Vector2f(0, 16);
    body.setPosition(position);
    slider.setPosition(Vector2f( position.x + (bodySize.x - sliderSize.x) / 2, position.y - (sliderSize.y - bodySize.y) / 2));
    edit = false;
    flag = false;
    min = _min;
    max = _max;

    ostringstream oss ;
    oss << getSliderValue();
    text.setString(initialText + oss.str());
}

bool Slider::isSliderClicked(RenderWindow *window)
{
    mousePos = Vector2f(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y);

    if (slider.getGlobalBounds().contains(mousePos) && mouseClickedOnce(Mouse::Left, flag))
    {
        edit = true;
        prevMousePos = mousePos;
    }

    if (!Mouse::isButtonPressed(Mouse::Left))
    {
        edit = false;
    }

    if (edit)
    {
        if(Keyboard::isKeyPressed(Keyboard::LControl))
        {
            slider.setPosition(slider.getPosition().x + (mousePos.x - prevMousePos.x) / 100.f, slider.getPosition().y);
        }
        else
        {
            slider.setPosition(slider.getPosition().x + (mousePos.x - prevMousePos.x) / 10.f, slider.getPosition().y);
        }

        Mouse::setPosition(Vector2i(slider.getPosition().x, slider.getPosition().y), *window);
        mousePos = Vector2f(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y);
        prevMousePos = mousePos;

        // boundings
        if( slider.getPosition().x >= body.getPosition().x + body.getSize().x - slider.getSize().x)
        {
            slider.setPosition(Vector2f(body.getPosition().x + body.getSize().x - slider.getSize().x, slider.getPosition().y));
        }

        if (slider.getPosition().x <= body.getPosition().x)
        {
            slider.setPosition(Vector2f(body.getPosition().x, slider.getPosition().y));
        }

        ostringstream oss;
        oss << getSliderValue();
        text.setString(initialText + oss.str());
        return true;
    }
    else
        return false;
}

float Slider::getSliderValue()
{
    return ((slider.getPosition().x - position.x) / ( body.getSize().x - slider.getSize().x) - 0.5) * (max - min) + (max + min) / 2 ;
}

void Slider::draw(RenderWindow &window)
{
    window.draw(body);
    window.draw(slider);
    window.draw(text);
}
