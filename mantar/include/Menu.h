#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <DisplayStack.h>
#include <Displayable.h>
#include <Game.h>


class Menu : public Displayable
{
    public:
        Menu(DisplayStack*);
        void processEvent(sf::Event);
        void update();
        void draw(sf::RenderWindow*);

    protected:
        void connect();

    private:
        tgui::Gui gui;
        DisplayStack* displayStack;
        Game game;
};

#endif // MENU_H
