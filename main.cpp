#include <iostream>
#include <SFML/Graphics.hpp>
#include "MO/Tank.h"
#include "SO/Wall.h"
#include "MO/Projectile.h"
#include <list>
#include "Menu.h"
#include "SO/StaticObject.h"
#include "MO/Tanks.h"
#include "SO/Bonuses.h"
#include "map.h"
using namespace sf;

void JoinEnemy(std::list<Tank>&list,Tank& tank,int& counter){
    if (counter>0) {
        list.push_back(tank);
        counter--;
    }

}
void JoinWall(std::list<StaticObject>&list, Wall& wall){
    list.push_back(wall);
}




int main() {
    sf::RenderWindow window(sf::VideoMode(1376, 768), "My First Game");
    int menuNum;
    //Menu(window,menuNum);
    view.reset(FloatRect (0,0,1276,668));
    Clock clock1;
    Image mapImage;
    mapImage.loadFromFile("Source/map.png");
    Texture mapTexture;
    mapTexture.loadFromImage(mapImage);
    Sprite mapSprite;
    mapSprite.setTexture(mapTexture);
    Image wallImage;
    wallImage.loadFromFile("Source/walls.png");
    Image mediumTankImage;
    mediumTankImage.loadFromFile("Tanks/mediumTank.png");
    Tank tank(200,200,75,50,mediumTankImage,1,"Player");

    std::list<StaticObject*> relief;
    std::list<StaticObject*>::iterator statIt;
    Wall* wall1=new Wall(100,100,50,50,wallImage,3,"wall1");




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
        window.draw(tank.getSprite());



                window.clear();
                ControlMap(time);
                window.setView(view);
                for (int i = 0; i < HEIGHT_MAP; i++)
                    for (int j = 0; j < WIDTH_MAP; j++)
                    {
                        if (TileMap[i][j] == 0)  mapSprite.setTextureRect(IntRect(0, 50, 50, 50));
                        if (TileMap[i][j] ==1) mapSprite.setTextureRect(IntRect(0, 0, 50, 50));



                mapSprite.setPosition(j * 50, i * 50);
                window.draw(mapSprite);
            }
        for (auto item:relief) {
            window.draw(item->getSprite());
            std::cout<<item->getX()<<item->getY()<<std::endl;

        }





        window.display();
    }
    return 0;
}

