#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tank.h"
#include "Wall.h"
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
        Image map_image;
        map_image.loadFromFile("Source/walls.png");
        Texture map;
        map.loadFromImage(map_image);
        Sprite s_map;
        s_map.setTexture(map);
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++) {
                if (TileMap[i][j] == ' ') s_map.setTextureRect(IntRect(150, 0, 50, 50));
                if (TileMap[i][j] == 's') s_map.setTextureRect(IntRect(32, 0, 32, 32));
                if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(0, 50, 50, 50));



                s_map.setPosition(j * 50, i * 50);
                window.draw(s_map);
            }



                window.draw(shape);
        window.display();
    }
    return 0;
}
