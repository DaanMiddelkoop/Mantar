#include "DisplayStack.h"

#include <iostream>

DisplayStack::DisplayStack(sf::RenderWindow* window)
{
    this->window = window;
    running = true;
}

void DisplayStack::run()
{
    int lowestActive = 0;
    for (int i = stack.size() - 1; i > 0; i--) {
        if (!active[i]) {
            lowestActive = i;
            break;
        }
    }

    sf::Event event;
    while (window->pollEvent(event))
    {
        std::cout << stack.size() << std::endl;
        for(int i = lowestActive; i < stack.size(); i++) {
            Displayable* displayable = stack[i];
            stack[i]->processEvent(event);
        }
    }

    for(int i = lowestActive; i < stack.size(); i++)
    {

        stack[i]->update();
    }

    int lowestVisible = 0;

    for (int i = stack.size() - 1; i > 0; i--) {
        if (!visible[i]) {
            lowestActive = i;
            break;
        }
    }

    window->clear();

    for (int i = lowestVisible; i < stack.size(); i++) {
        stack[i]->draw(window);
    }

    std::cout << "displaying" << std::endl;
    window->display();
}

void DisplayStack::add(Displayable* displayable, bool active, bool visible)
{
    stack.push_back(displayable);
    std::cout << stack.size() << std::endl;
    this->active.push_back(active);
    this->visible.push_back(visible);
}

void DisplayStack::pop(int index)
{
    if (stack.size() - 1 - index < 0 || -1 - index >= 0) {
        return;
    }
    stack.erase(stack.begin() + stack.size() - 1 - index);
    active.erase(active.begin() + stack.size() - 1 - index);
    visible.erase(visible.begin() + stack.size() - 1 - index);
}

void DisplayStack::popLast()
{
    if (stack.size() > 0) {
        active.pop_back();
        visible.pop_back();
        stack.pop_back();
    }
}


void DisplayStack::close()
{
    this->running = false;
}

bool DisplayStack::isRunning()
{
    return this->running;
}

sf::RenderWindow* DisplayStack::getWindow()
{
    return this->window;
}
