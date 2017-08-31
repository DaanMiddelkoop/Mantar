#ifndef NETWORK_H
#define NETWORK_H

#include <NetworkMessageHandler.h>
#include <SFML/Network.hpp>

class Network
{
    public:
        Network();
        void connect(std::string ip, int port);
        void setMessageHandler(NetworkMessageHandler*);

    protected:
    private:
        NetworkMessageHandler* messageHandler;
        sf::TcpSocket socket;
};

#endif // NETWORK_H
