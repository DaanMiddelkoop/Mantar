#ifndef DISPLAYSTACK_H
#define DISPLAYSTACK_H

#include <SFML/Graphics.hpp>
#include <Displayable.h>
#include <memory>

class DisplayStack
{
    public:
        DisplayStack(sf::RenderWindow*);
        void run();
        void add(std::shared_ptr<Displayable>, bool, bool);
        void pop(int);
        void popLast();
        void close();
        bool isRunning();
        sf::RenderWindow* getWindow();

    protected:

    private:
        sf::RenderWindow* window;
        std::vector<std::shared_ptr<Displayable>> stack;
        std::vector<bool> active;
        std::vector<bool> visible;
        bool running;
};

#endif // DISPLAYSTACK_H
