#include "Menu.h"

Menu::Menu(DisplayStack* displayStack)
{
    this->displayStack = displayStack;

    tgui::Button::Ptr connectButton = tgui::Button::create("Connect");
    tgui::TextBox::Ptr ipBox = tgui::TextBox::create();
    tgui::Button::Ptr quitButton = tgui::Button::create("Quit");



    connectButton->connect("pressed", Menu::connect, this);
    quitButton->connect("pressed", [&](){this->displayStack->close();});

    auto width = tgui::bindWidth(gui);
    auto height = tgui::bindHeight(gui);

    connectButton->setPosition((width / 2) - tgui::bindWidth(connectButton) / 2, (height / 2) - tgui::bindHeight(connectButton) / 2 - 50);
    ipBox->setSize(tgui::bindWidth(connectButton), tgui::bindHeight(connectButton));
    ipBox->setPosition((width / 2) - tgui::bindWidth(ipBox) / 2, (height / 2) - tgui::bindHeight(ipBox) / 2);
    quitButton->setPosition((width / 2) - tgui::bindWidth(quitButton) / 2, (height / 2) - tgui::bindHeight(quitButton) / 2 + 50);

    gui.add(connectButton);
    gui.add(ipBox);
    gui.add(quitButton);

    gui.setWindow(*displayStack->getWindow());

    std::cout << "testing end Menu constructor"<< std::endl;
}

void Menu::processEvent(sf::Event event)
{
    gui.handleEvent(event);
}

void Menu::update()
{

}

void Menu::draw(sf::RenderWindow* window)
{
    gui.draw();
}

void Menu::connect()
{
    std::shared_ptr<Game> game (new Game(displayStack));
    this->game = game;
    displayStack->add(game, false, false);
}
