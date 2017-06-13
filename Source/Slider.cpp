#include "stdafx.h"
#include "Slider.h"


Slider::Slider()
{

	track.setFillColor(sf::Color(90, 90, 90, 180));
	knob.setFillColor(sf::Color(200, 200, 200, 200));

	track.setPosition(40, 40);
	knob.setPosition(40 + (100 / 2) - 10, 40 - 10);
}


Slider::~Slider()
{
}



sf::RectangleShape Slider::getTrack(){
	return track;
}

sf::RectangleShape Slider::getKnob(){
	return knob;
}

void Slider::drawSlider(sf::RenderWindow *window){
	
	window->draw(track);
	window->draw(knob);
}