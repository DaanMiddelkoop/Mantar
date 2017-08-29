#include <SFML/Graphics.hpp>

#include "Menu.h";

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    Menu menu(&window);
    menu.start();

    return EXIT_SUCCESS;
}
