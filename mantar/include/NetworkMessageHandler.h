#ifndef NETWORKMESSAGEHANDLER_H
#define NETWORKMESSAGEHANDLER_H

#include <SFML/Graphics.hpp>
#include <TGUI/Gui.hpp>
#include <Displayable.h>
#include <DisplayStack.h>

class NetworkMessageHandler : public Displayable
{
    public:
        NetworkMessageHandler(DisplayStack*, std::string);
        void processEvent(sf::Event);
        void update();
        void draw(sf::RenderWindow*);

    protected:

    private:
        tgui::Gui gui;
};

#endif // NETWORKMESSAGEHANDLER_H
