#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>


class Menu
{
    public:
        Menu(sf::RenderWindow*);
        start();

    protected:

    private:
        connect();

        sf::RenderWindow* window;
        sf::Vector2u screenSize;

};

#endif // MENU_H
