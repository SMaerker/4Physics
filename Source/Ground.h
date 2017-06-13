#pragma once
class Ground
{
public:
	Ground();
	~Ground();

	void drawGround(sf::RenderWindow *window);
private:

	sf::RectangleShape body = sf::RectangleShape(sf::Vector2f(800.0, 1.0));

	float Height;
};

