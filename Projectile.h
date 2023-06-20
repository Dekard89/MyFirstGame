
#ifndef TEST1_PROJECTILE_H
#define TEST1_PROJECTILE_H
#include <string>
#include <SFML/Graphics.hpp>
#include "MovingObject.h"
#include "Tank.h"
#include "map.h"

using namespace sf;

class Projectile: public MovingObject,IDesrtroyed{
protected:
    float damage=1;
    bool life=true;
    int dir;
    std::string path="Source/Projectile.png";
    int factorOfSpeed=10;
public:
    float getDamage() const {
        return damage;
    }

    Projectile(float x, float y,int dir) : MovingObject(x, y,dir, h, w,image),damage(damage) {
        image.loadFromFile(path);
        h=50;
        w=50;
        sprite.setTextureRect(IntRect(0,0,w,h));
        this->x=x;
        this->y=y;


    }

    void Desroyed() override{
        for (int i = 0; i < WIDTH_MAP; ++i)
            for (int j = 0; j < HEIGHT_MAP; ++j) {
                if(this->getDamage()=='o'){
                    this->life= false;
            }

        }
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
            sprite.setTextureRect(IntRect (0,100,50,50));
    }




};


#endif //TEST1_PROJECTILE_H
