#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Color.h"

class Pawn
{
private:
	sf::Texture pawnTexture;
	sf::Sprite pawnSprite;
	sf::Vector2f pawnPos;
	Color colorType;
	int player;
public:
	//Variables
	bool isHome = true;

	//Functions
	Pawn();
	Pawn(sf::Vector2f pos, sf::Texture text, Color col, int pl);
	Pawn(int x, int y, sf::Texture text, Color col, int pl);
	~Pawn();
	void renderPawn(sf::RenderWindow& window);
};

