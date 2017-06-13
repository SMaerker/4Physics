#pragma once
class Block
{
public:
	Block(sf::Vector2i coords, float time);
	~Block();

	
	sf::RectangleShape getBody();

	void updatePosition(float time);

	void drawBlock(sf::RenderWindow *window);

private:
	sf::RectangleShape body;

	sf::Vector2f accel = sf::Vector2f(0.0, 200.0);
	sf::Vector2f velocity = sf::Vector2f(0.0, 0.0);
	sf::Vector2f position = sf::Vector2f(0.0, 0.0);

	float timeInitial;
};

