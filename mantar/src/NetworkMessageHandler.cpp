#include "NetworkMessageHandler.h"
#include <TGUI/TGUI.hpp>

#include <iostream>

NetworkMessageHandler::NetworkMessageHandler(DisplayStack* displayStack, std::string message)
{
    std::cout << "testing begin networkMessageHandler constructor" << std::endl;
    tgui::ChildWindow::Ptr messageBox;
    gui.add(messageBox);

    tgui::Label::Ptr label;
    messageBox->add(label);
    label->setText(message);

    tgui::Button::Ptr button;
    messageBox->add(button);
    button->setText("Oke");

    button->connect("released", [&](){
        gui.removeAllWidgets();
        displayStack->popLast();
    });

    gui.setWindow(*displayStack->getWindow());
    std::cout << "testing end networkmessagehandler constructor" << std::endl;
}

void NetworkMessageHandler::processEvent(sf::Event event)
{
    gui.handleEvent(event);
}

void NetworkMessageHandler::update()
{

}

void NetworkMessageHandler::draw(sf::RenderWindow* window)
{
    gui.draw();
}
