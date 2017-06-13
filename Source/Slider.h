#pragma once
#include "stdafx.h"
class Slider
{
public:
	Slider();
	~Slider();


	sf::RectangleShape getTrack();
	sf::RectangleShape getKnob();


	void drawSlider(sf::RenderWindow *window);

private:
	sf::RectangleShape track = sf::RectangleShape(sf::Vector2f(100, 10));
	sf::RectangleShape knob = sf::RectangleShape(sf::Vector2f(20, 30));
};

