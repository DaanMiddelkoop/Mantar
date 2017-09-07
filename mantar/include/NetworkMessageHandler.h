#ifndef NETWORKMESSAGEHANDLER_H
#define NETWORKMESSAGEHANDLER_H

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Displayable.h>
#include <DisplayStack.h>
#include <iostream>

class NetworkMessageHandler : public Displayable
{
    public:
        template<typename Func, typename... Args>
        NetworkMessageHandler(DisplayStack* displayStack, std::string message, Func callBack, Args... arguments)
        {
            gui.setWindow(*displayStack->getWindow());
            tgui::ChildWindow::Ptr messageBox = tgui::ChildWindow::create();
            gui.add(messageBox);

            tgui::Label::Ptr label = tgui::Label::create(message);
            messageBox->add(label);
            label->setText(message);

            tgui::Button::Ptr button = tgui::Button::create("Oke");
            messageBox->add(button);
            button->setText("Oke");

            button->connect("pressed", [&](){
                gui.removeAllWidgets();
                displayStack->popLast();
            });
            button->connect("pressed", callBack, arguments...);
            gui.add(button);
            std::cout << "this happened" << std::endl;
        }

        void processEvent(sf::Event);
        void update();
        void draw(sf::RenderWindow*);

    protected:

    private:
        tgui::Gui gui;
};

#endif // NETWORKMESSAGEHANDLER_H
