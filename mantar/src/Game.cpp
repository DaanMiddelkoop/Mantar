#include "Game.h"

Game::Game(DisplayStack* displayStack)
{
    network.connect("127.0.0.1", 25500);
    this->displayStack = displayStack;
    gui.setWindow(*displayStack->getWindow());
}

void Game::processEvent(sf::Event event)
{
    gui.handleEvent(event);
}

void Game::update()
{

}

void Game::draw(sf::RenderWindow* window)
{

}
