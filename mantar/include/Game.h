#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <TGUI/Gui.hpp>

#include "Network.h"
#include <Displayable.h>
#include <DisplayStack.h>


class Game : public Displayable
{
    public:
        Game(DisplayStack*);
        void processEvent(sf::Event);
        void update();
        void draw(sf::RenderWindow* window);

    protected:

    private:
        tgui::Gui gui;
        Network network;
        DisplayStack* displayStack;
        //Map map;
};

#endif // GAME_H
