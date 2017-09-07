#include <SFML/Graphics.hpp>

#include "Menu.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    window.setFramerateLimit(10);
    tgui::Gui gui(window);

    DisplayStack displayStack(&window);

    std::shared_ptr<Displayable> menu(new Menu(&displayStack));
    displayStack.add(menu, false, false);

    while (displayStack.isRunning()) {
        displayStack.run();
    }
    window.close();

    return EXIT_SUCCESS;
}
