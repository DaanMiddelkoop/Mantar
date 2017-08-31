#include <SFML/Graphics.hpp>

#include "Menu.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    window.setFramerateLimit(10);
    tgui::Gui gui(window);

    DisplayStack displayStack(&window);

    Menu menu(&displayStack);
    displayStack.add(&menu, false, false);
    std::cout << &menu << std::endl;

    std::cout << "testing before game loop" << std::endl;

    while (displayStack.isRunning()) {
        displayStack.run();
    }
    window.close();

    return EXIT_SUCCESS;
}
