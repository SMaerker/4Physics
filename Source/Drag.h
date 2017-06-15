#pragma once
class Drag
{
public:
	Drag();
	~Drag();

	void updateInit(sf::Vector2i initialCoords);
	void updateEnd(sf::Vector2i currentCoords);

	void drawIndicator(sf::RenderWindow *window);

	void setUse(bool use);

private:
	const int kConst = 1;

	bool inUse;

	sf::RectangleShape indicator;
	sf::Vector2i initCoords;
	sf::Vector2i currCoords;


};

