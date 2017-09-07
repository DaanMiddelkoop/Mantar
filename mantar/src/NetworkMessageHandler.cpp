#include "NetworkMessageHandler.h"
#include <TGUI/TGUI.hpp>

#include <iostream>

void NetworkMessageHandler::processEvent(sf::Event event)
{
    gui.handleEvent(event);
}

void NetworkMessageHandler::update()
{

}

void NetworkMessageHandler::draw(sf::RenderWindow* window)
{
    std::cout << "test" << std::endl;
    gui.draw();
}
