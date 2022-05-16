#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Pawn.h"

class Game 
{
private:

	//Variables
	int WIDTH = 920; //1280
	int HEIGHT = 920; //720
	sf::Event event;
	sf::Vector2i mousePos;
	int whichPlayer = 1;

	//Background
	sf::Texture backgroundTexture;
	sf::Sprite backroundSprite;

	//Pawns
	std::vector <Pawn> pawns;
	int x1 = 75;
	int y1 = 85;

	//Gameplay
	int diceRoll;
	void rollTheDice();

	//Functions
	void initWindow();
	void initTextures();
	void initPawns();
	void updateMousePos();
	void updatePawns();

public:

	//Variables
	sf::RenderWindow* window;

	//Constructors
	Game();
	virtual ~Game();

	//Getters Accessors
	const bool isWindowOpen();

	//Functions
	void initAll();
	void pollEvents();
	void frameUpdate();
	void render();
};

