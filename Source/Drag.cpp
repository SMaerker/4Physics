#include "stdafx.h"
#include "Drag.h"


Drag::Drag(){
	indicator.setFillColor(sf::Color::White);
	indicator.setSize(sf::Vector2f(0.0, 1.0));
	inUse = false;
}


Drag::~Drag(){
}

void Drag::updateInit(sf::Vector2i initialCoords){
	initCoords = initialCoords;
	indicator.setPosition(static_cast<float>(initCoords.x), static_cast<float>(initCoords.y));
}

void Drag::updateEnd(sf::Vector2i currentCoords){
	if (inUse){ currCoords = currentCoords; }
}

void Drag::drawIndicator(sf::RenderWindow *window){
	if (inUse){
		indicator.setSize(sf::Vector2f(sqrt(pow(currCoords.x - initCoords.x, 2) + pow(currCoords.y - initCoords.y, 2)), 1.0));

		indicator.setRotation(atan2((currCoords.y - initCoords.y), (currCoords.x - initCoords.x)) * (180 / 3.14159));

		window->draw(indicator);
	}
}

void Drag::setUse(bool use){
	inUse = use;
}
