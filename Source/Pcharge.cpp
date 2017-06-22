#include "stdafx.h"
#include "Pcharge.h"


Pcharge::Pcharge(sf::Vector2i coords, float time)
{
	timeInitial = time;
	position = sf::Vector2f(static_cast<float>(coords.x), static_cast<float>(coords.y));



	body.setPosition(position);
	body.setFillColor(sf::Color::Transparent);
	body.setOutlineColor(sf::Color::White);
	body.setOutlineThickness(1.0);
	body.setRadius(30);
}


Pcharge::~Pcharge()
{
}


sf::CircleShape Pcharge::getBody(){
	return body;
}

void Pcharge::updatePosition(float time){

	timeInitial = time;
}

void Pcharge::drawCharge(sf::RenderWindow *window){
	window->draw(body);
}