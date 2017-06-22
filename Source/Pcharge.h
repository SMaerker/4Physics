#pragma once
class Pcharge
{
public:
	Pcharge(sf::Vector2i coords, float time);
	~Pcharge();

	sf::CircleShape getBody();

	void updatePosition(float time);

	void drawCharge(sf::RenderWindow *window);


private:
	sf::CircleShape body;

	sf::Vector2f accel = sf::Vector2f(0.0, 0.0);
	sf::Vector2f velocity = sf::Vector2f(0.0, 0.0);
	sf::Vector2f position = sf::Vector2f(0.0, 0.0);

	int charge;
	float timeInitial = 0;
};

