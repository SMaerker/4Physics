#include "stdafx.h"
#include "Block.h"


Block::Block(sf::Vector2i coords, float time)
{
	timeInitial = time;
	position = sf::Vector2f(static_cast<float>(coords.x), static_cast<float>(coords.y));
	body.setPosition(position);
	body.setFillColor(sf::Color::Red);
	body.setSize(sf::Vector2f(30.0, 20.0));
}


Block::~Block()
{
}


sf::RectangleShape Block::getBody(){
	return body;
}


void Block::updatePosition(float time){

	if (body.getPosition().y < 475 - 20){
		velocity.y += accel.y * (time - timeInitial);
		position.y += velocity.y * (time - timeInitial);
		body.setPosition(position);
	}

	else{
		body.setPosition(sf::Vector2f(body.getPosition().x, 475 - 20));
	}


	timeInitial = time;
}


void Block::drawBlock(sf::RenderWindow *window){
	window->draw(body);
}