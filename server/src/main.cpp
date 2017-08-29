#include <SFML/Network.hpp>
#include <iostream>

int main()
{
    sf::TcpListener listener;
    listener.listen(25500);
    while (true) {
        sf::TcpSocket socket;
        listener.accept(socket);
        std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
    }


    return EXIT_SUCCESS;
}
