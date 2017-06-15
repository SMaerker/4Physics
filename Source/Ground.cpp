#include "stdafx.h"
#include "Ground.h"


Ground::Ground()
{
	body.setFillColor(sf::Color::White);
	body.setPosition(0, 475);
}


Ground::~Ground()
{
}

void Ground::drawGround(sf::RenderWindow *Window){
	Window->draw(body);
}
