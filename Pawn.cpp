#include "Pawn.h"

Pawn::Pawn()
{

}


Pawn::Pawn(int x, int y, sf::Sprite spr, Color col, int pl)
{
	pawnPos = sf::Vector2f(x, y);
	colorType = col;
	pawnSprite = spr;
	pawnSprite.setOrigin(pawnSprite.getTexture()->getSize().x / 2, pawnSprite.getTexture()->getSize().y);
	pawnSprite.setPosition(pawnPos);
	switch (col) {
	case Color::RED:
		pawnSprite.setColor(sf::Color::Red);
		break;
	case Color::BLUE:
		pawnSprite.setColor(sf::Color::Blue);
		break;
	case Color::YELLOW:
		pawnSprite.setColor(sf::Color::Yellow);
		break;
	case Color::GREEN:
		pawnSprite.setColor(sf::Color::Green);
		break;
	}
	player = pl;
}

Pawn::~Pawn() 
{

}

void Pawn::renderPawn(sf::RenderWindow& window) {
	window.draw(pawnSprite);
}