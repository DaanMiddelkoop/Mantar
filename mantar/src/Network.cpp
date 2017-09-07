#include "Network.h"

Network::Network(DisplayStack* displayStack)
{
    this->displayStack = displayStack;
}

void Network::connect(std::string ip, int port) {
    if(socket.connect(ip, port) != sf::Socket::Done)
	{
        showMessage((std::string)"Failed to connect.", DisplayStack::popLast, displayStack);
    }
}

template<typename Func, typename... Args>
void Network::showMessage(std::string message, Func callBack, Args... arguments)
{
    std::shared_ptr<NetworkMessageHandler> messageHandler(new NetworkMessageHandler(displayStack, message, callBack, arguments...));
    displayStack->add(messageHandler, false, true);
    std::cout << "test" << std::endl;
}

