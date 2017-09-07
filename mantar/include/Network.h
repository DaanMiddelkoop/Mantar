#ifndef NETWORK_H
#define NETWORK_H

#include <NetworkMessageHandler.h>
#include <SFML/Network.hpp>
#include <DisplayStack.h>

class Network
{
    public:
        Network(DisplayStack* displayStack);
        void connect(std::string ip, int port);

        template<typename Func, typename... Args>
        void showMessage(std::string, Func, Args...);

    protected:
    private:
        sf::TcpSocket socket;
        DisplayStack* displayStack;
};

#endif // NETWORK_H
