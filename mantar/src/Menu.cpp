#include <TGUI/TGUI.hpp>

#include "Menu.h"

Menu::Menu(sf::RenderWindow* window)
{
    this->window = window;
    this->screenSize = window->getSize();
}

Menu::start() {
    tgui::Gui gui(*window);
    tgui::Button::Ptr connectButton = tgui::Button::create("Connect");
    tgui::Button::Ptr quitButton = tgui::Button::create("Quit");

    connectButton->connect("pressed", Menu::connect, this);
    quitButton->connect("pressed", [&](){ window->close(); });

    auto width = tgui::bindWidth(gui);
    auto height = tgui::bindHeight(gui);

    connectButton->setPosition((width / 2) - tgui::bindWidth(connectButton) / 2, (height / 2) - tgui::bindHeight(connectButton) / 2);


    gui.add(connectButton);
    gui.add(quitButton);

    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();

                gui.handleEvent(event);
        }

        // Clear screen
        window->clear();
        gui.draw();

        // Update the window
        window->display();
    }
}

Menu::connect() {
    window->create(sf::VideoMode(1280, 720), "BIGGER SCREEEEEEEN");
}
