#include "Pawn.h"

Pawn::Pawn()
{

}

Pawn::Pawn(sf::Vector2f pos, sf::Texture text, Color col, int pl)
{
	pawnPos = pos;
	pawnTexture = text;
	colorType = col;
	pawnSprite.setTexture(pawnTexture);
	pawnSprite.setScale(0.22, 0.22);
	pawnSprite.setOrigin(pawnTexture.getSize().x / 2, pawnTexture.getSize().y);
	pawnSprite.setPosition(pawnPos);
	player = pl;
}

Pawn::Pawn(int x, int y, sf::Texture text, Color col, int pl)
{
	pawnPos = sf::Vector2f(x, y);
	pawnTexture = text;
	colorType = col;
	pawnSprite.setTexture(pawnTexture);
	pawnSprite.setScale(0.22, 0.22);
	pawnSprite.setOrigin(pawnTexture.getSize().x / 2, pawnTexture.getSize().y);
	pawnSprite.setPosition(pawnPos);
	player = pl;
}

Pawn::~Pawn() 
{

}

void Pawn::renderPawn(sf::RenderWindow& window) {
	window.draw(pawnSprite);
}