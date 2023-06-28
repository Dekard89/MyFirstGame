
#ifndef TEST1_PROJECTILE_H
#define TEST1_PROJECTILE_H
#include <string>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Tank.h"
#include "../map.h"
#include "../IDesrtroyed.h"

using namespace sf;

class Projectile: public MovingObject{
private:
    int damage=1;
    int factorOfSpeed=10;
public:
    float getDamage() const {
        return damage;
    }

    Projectile(float x, float y,int dir) : MovingObject(x, y, h, w, image,dir),damage(damage) {
        h=50;
        w=50;
        image.loadFromFile("Source/Projectile.png");
        sprite.setTextureRect(IntRect(0,0,w,h));
        this->x=x;
        this->y=y;


    }

    void Desroyed() override{
        life= false;
            }



    void Shoted(float time){
        speed*=factorOfSpeed;
        float currentFrame;
        currentFrame+=0.005*time;
        image.loadFromFile("Source/shoot.png");
        image.createMaskFromColor(Color(70,73,114));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(50*int (currentFrame),0,50,50));
        if (currentFrame>2)
            return;
    }
    void Update(float time) override{
        switch (dir) {
            case 0:
                bustX=0;
                bustY=speed;
                break;
            case 1:
                bustX=0;
                bustY=-speed;
                break;
            case 2:
                bustX=speed;
                bustY=0;
                break;
            case 3:
                bustX=-speed;
                bustY=0;
                break;
        }
        x+=bustX*time;
        y+=bustY*time;
        speed=0;
        sprite.setPosition(x,y);

        for (int i = y / 50; i < (y + h) / 50; i++)
            for (int j = x / 50; j<(x + w) / 50; j++) {
                if (TileMap[i][j] == '0'||TileMap[i][j]=='w')
                    Desroyed();
        }
    }




};


#endif //TEST1_PROJECTILE_H
