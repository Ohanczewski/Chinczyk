#include "Game.h"

//Overloading operators
std::ostream& operator<<(std::ostream& out, const sf::Vector2f v) {
	out << "[" << v.x << ", " << v.y << "]";
	return out;
}
std::ostream& operator<<(std::ostream& out, const sf::Vector2i v) {
	out << "[" << v.x << ", " << v.y << "]";
	return out;
}
sf::Vector2i operator+(sf::Vector2i v1, sf::Vector2i v2) {
	return sf::Vector2i(v1.x + v2.x, v1.y + v2.y);
}

//Helper functions
void Game::rollTheDice() {
	diceRoll = rand() % 6 + 1;
	//std::cout << diceRoll << std::endl;
}

//Constructors & Destructors
Game::Game() 
{

}
void Game::initAll() 
{
	initWindow();
	initTextures();
	initPawns();
}
Game::~Game() 
{
	delete this->window;
}

void Game::initWindow() 
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Chinczyk", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings::ContextSettings(0, 0, 10, 2, 0));
	//window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(10);
}
void Game::initTextures() 
{
	backgroundTexture.loadFromFile("assets/textures/background.png");
	backgroundTexture.setSmooth(true);
	backroundSprite.setTexture(backgroundTexture);
	backroundSprite.setScale(sf::Vector2f(0.898f, 0.898f));
}

void Game::initPawns()
{
	//Red ones
	sf::Texture pawnText;
	pawnText.loadFromFile("assets/textures/pawnTexture.jpg");
	pawns.emplace_back(Pawn(x1, y1, pawnText, Color::RED, 1));
	pawns.emplace_back(Pawn(x1 + 80, y1, pawnText, Color::RED, 1));
	pawns.emplace_back(Pawn(x1, y1 + 80, pawnText, Color::RED, 1));
	pawns.emplace_back(Pawn(x1 + 80, y1 + 80, pawnText, Color::RED, 1));

	pawns.emplace_back(Pawn(x1 + 690, y1, pawnText, Color::BLUE, 2));
	pawns.emplace_back(Pawn(x1 + 690 + 80, y1, pawnText, Color::BLUE, 2));
	pawns.emplace_back(Pawn(x1 + 690, y1 + 80, pawnText, Color::BLUE, 2));
	pawns.emplace_back(Pawn(x1 + 690 + 80, y1 + 80, pawnText, Color::BLUE, 2));

	pawns.emplace_back(Pawn(x1, y1 + 690, pawnText, Color::YELLOW, 3));
	pawns.emplace_back(Pawn(x1 + 80, y1 + 690, pawnText, Color::YELLOW, 3));
	pawns.emplace_back(Pawn(x1, y1 + 690 + 80, pawnText, Color::YELLOW, 3));
	pawns.emplace_back(Pawn(x1 + 80, y1 + 690 + 80, pawnText, Color::YELLOW, 3));

	pawns.emplace_back(Pawn(x1 + 690, y1 + 690, pawnText, Color::GREEN, 4));
	pawns.emplace_back(Pawn(x1 + 690 + 80, y1 + 690, pawnText, Color::GREEN, 4));
	pawns.emplace_back(Pawn(x1 + 690, y1 + 690 + 80, pawnText, Color::GREEN, 4));
	pawns.emplace_back(Pawn(x1 + 690 + 80, y1 + 690 + 80, pawnText, Color::GREEN, 4));
}

void Game::updateMousePos()
{
	mousePos = sf::Mouse::getPosition(*window);
}

void Game::updatePawns() 
{
	switch (whichPlayer) {
	case 1:
		if (pawns[0].isHome && pawns[1].isHome && pawns[2].isHome && pawns[3].isHome) {
			if (diceRoll == 6) {
				std::cout << "Gracz 1 wyrzucil 6!" << std::endl;
			}
		}
		else {

		}
		break;
	case 2:
		if (pawns[4].isHome && pawns[5].isHome && pawns[6].isHome && pawns[7].isHome) {
			if (diceRoll == 6) {
				std::cout << "Gracz 2 wyrzucil 6!" << std::endl;
			}
		}
		break;
	case 3:
		if (pawns[8].isHome && pawns[9].isHome && pawns[10].isHome && pawns[11].isHome) {
			if (diceRoll == 6) {
				std::cout << "Gracz 3 wyrzucil 6!" << std::endl;
			}
		}
		break;
	case 4:
		if (pawns[12].isHome && pawns[13].isHome && pawns[14].isHome && pawns[15].isHome) {
			if (diceRoll == 6) {
				std::cout << "Gracz 4 wyrzucil 6!" << std::endl;
			}
		}
		break;
	}
}

//Getters Accessors
const bool Game::isWindowOpen() 
{
	return this->window->isOpen();
}

void Game::pollEvents() 
{

	while (this->window->pollEvent(event)) 
	{
		switch (event.type) 
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			//Keys pressed
			if (event.key.code == sf::Keyboard::Escape) 
			{
				window->close();
			}
			if (event.key.code == sf::Keyboard::Space) //Determining that player is changing
			{
				//Dice throw
				rollTheDice();
				updatePawns();
				if (whichPlayer == 4) {
					whichPlayer = 1;
				}
				else {
					whichPlayer++;
				}
			}

			break;
		}
	}
}

void Game::frameUpdate() 
{
	pollEvents();
	updateMousePos();
}

void Game::render() 
{
	window->clear(sf::Color::Black);

	//Rendering things
	window->draw(backroundSprite);
	//std::cout << mousePos << std::endl;

	//Rendering pawns
	for (auto& i : pawns) {
		i.renderPawn(*window);
	}

	window->display();
}