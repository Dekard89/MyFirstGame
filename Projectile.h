
#ifndef TEST1_PROJECTILE_H
#define TEST1_PROJECTILE_H
#include <string>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Tank.h"

using namespace sf;

class Projectile: public MovingObject,IDesrtroyed{
public:
    float damage=1;
    bool life=true;
    int dir;
    std::string path="Source/Projectile.png";
    int factorOfSpeed=10;

    Projectile(float x, float y,int dir) : MovingObject(x, y,dir, h, w,image),damage(damage) {
        image.loadFromFile(path);
        h=50;
        w=50;
        sprite.setTextureRect(IntRect(0,0,w,h));
        this->x=x;
        this->y=y;


    }

    void Desroyed() override{
        //if(this->getRect()==)
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




};


#endif //TEST1_PROJECTILE_H
