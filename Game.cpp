#include "Game.h"

//Overloading operators
std::ostream& operator<<(std::ostream& out, const sf::Vector2f v) {
	out << "[" << v.x << ", " << v.y << "]";
	return out;
}
sf::Vector2i operator+(sf::Vector2i v1, sf::Vector2i v2) {
	return sf::Vector2i(v1.x + v2.x, v1.y + v2.y);
}

//Constructors & Destructors
Game::Game() {

}
void Game::initAll() {
	initWindow();
}
Game::~Game() {
	delete this->window;
}

void Game::initWindow() {
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Chinczyk", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings::ContextSettings(0, 0, 10, 2, 0));
	//window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window->setFramerateLimit(60);
}

//Getters Accessors
const bool Game::isWindowOpen() {
	return this->window->isOpen();
}

void Game::pollEvents() {

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
			break;
		}
	}
}

void Game::frameUpdate() {
	pollEvents();

}

void Game::render() {

	window->clear(sf::Color::Cyan);

	window->display();
}