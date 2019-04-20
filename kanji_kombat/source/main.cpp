#include "SFML/Graphics.hpp"

int main(int argc, char ** argv) {
    sf::RenderWindow renderWindow(sf::VideoMode(1024, 768), "SFML Demo");

    sf::Event event;
    while (renderWindow.isOpen()) {
        // Check for all the events that occured since the last frame.
        while (renderWindow.pollEvent(event)) {
            //Handle events here
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        renderWindow.clear();
        renderWindow.display();
    }

}