#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tank.h"
using namespace sf;
int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Green);
    Clock clock1;



    while (window.isOpen())
    {
        float time=clock1.getElapsedTime().asMicroseconds();
        clock1.restart();
        time=time/800;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
