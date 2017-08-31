#ifndef DISPLAYSTACK_H
#define DISPLAYSTACK_H

#include <SFML/Graphics.hpp>
#include <Displayable.h>

class DisplayStack
{
    public:
        DisplayStack(sf::RenderWindow*);
        void run();
        void add(Displayable*, bool, bool);
        void pop(int);
        void popLast();
        void close();
        bool isRunning();
        sf::RenderWindow* getWindow();

    protected:

    private:
        sf::RenderWindow* window;
        std::vector<Displayable*> stack;
        std::vector<bool> active;
        std::vector<bool> visible;
        bool running;
};

#endif // DISPLAYSTACK_H
