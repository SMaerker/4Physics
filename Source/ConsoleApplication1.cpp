//TODO
//Optimize checks in updatePosition

#include "stdafx.h"
#include <SFML\Graphics.hpp>


#include "Slider.h"
#include "Block.h"
#include "Ground.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//Window Dimensions
	int width = 800;
	int height = 500;
	
	//Initialize window
	sf::RenderWindow window(sf::VideoMode(width, height), "Sort!");
	window.setFramerateLimit(60.0f);

	//Timestep setup
	sf::Time time;
	sf::Clock clock;

	//Population for Blocks
	std::vector<Block> population;

	//Ground
	Ground floor;

	//Should get rid of this for now but oh well.
	Slider foo;


	while (window.isOpen())
	{ 
		sf::Event event;
		while (window.pollEvent(event)){

			//close window
			if (event.type == sf::Event::Closed){	
				window.close();	
			}

			
			else if (event.type == sf::Event::MouseButtonPressed){

				//Check to see if click is inside the knob of a slider
				if ((static_cast<float>(sf::Mouse::getPosition(window).x) < (foo.getKnob().getPosition().x + foo.getKnob().getSize().x) && static_cast<float>(sf::Mouse::getPosition(window).x) > (foo.getKnob().getPosition().x)) &&	//casted to floats as shape positions are floats.
					(static_cast<float>(sf::Mouse::getPosition(window).y) < (foo.getKnob().getPosition().y + foo.getKnob().getSize().y) && static_cast<float>(sf::Mouse::getPosition(window).y) > (foo.getKnob().getPosition().y))){
					printf("inside knob\n");
				}

				//Create a new block
				else{
					population.push_back(Block(sf::Vector2i(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y), time.asSeconds()));
				}

			}


		}

		window.clear();

		//Draw the blocks
		for (int i = 0; i < population.size(); i++){
			population.at(i).drawBlock(&window);
		}

		floor.drawGround(&window);

		window.display();

		time += clock.restart();

		//Update positions
		for (int i = 0; i < population.size(); i++){
			population.at(i).updatePosition(time.asSeconds());
		}
	}


	return 0;
}

