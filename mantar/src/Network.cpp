#include "Network.h"

Network::Network()
{
}

void Network::setMessageHandler(NetworkMessageHandler* messageHandler)
{
    this->messageHandler = messageHandler;
}

void Network::connect(std::string ip, int port) {
    if(socket.connect(ip, port) != sf::Socket::Done)
	{

    }
}

