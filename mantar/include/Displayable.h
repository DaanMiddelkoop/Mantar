#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include <SFML/Graphics.hpp>

class Displayable
{
    public:
        virtual void processEvent(sf::Event) = 0;
        virtual void update() = 0;
        virtual void draw(sf::RenderWindow*) = 0;
    protected:

    private:
};

#endif // DISPLAYABLE_H
