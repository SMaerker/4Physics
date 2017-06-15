#include "stdafx.h"
#include "Block.h"


Block::Block(sf::Vector2i coords, sf::Vector2i vel, float time)
{
	timeInitial = time;
	position = sf::Vector2f(static_cast<float>(coords.x), static_cast<float>(coords.y));
	velocity = sf::Vector2f(static_cast<float>(vel.x), static_cast<float>(vel.y));


	body.setPosition(position);
	body.setFillColor(sf::Color::Transparent);
	body.setOutlineColor(sf::Color::White);
	body.setOutlineThickness(1.0);
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
		velocity += accel * (time - timeInitial);
		position += velocity * (time - timeInitial);
		body.setPosition(position);
	}

	else{
		body.setPosition(sf::Vector2f(body.getPosition().x, 475 - 20));
		velocity.x = 0;
	}


	timeInitial = time;
}


void Block::drawBlock(sf::RenderWindow *window){
	window->draw(body);
}