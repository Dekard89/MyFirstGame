
#ifndef TEST1_WALL_H
#define TEST1_WALL_H
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "../IDesrtroyed.h"
#include <string>
#include "../MO/Projectile.h"

using namespace sf;

class Wall: public StaticObject {
private:



public:
    Wall(float  x,float y, float h, float w, Image &image, int armor, const std::string &name)
            : StaticObject(x, y, h, w, image, armor, name, damage) {


}

    int TakeDamage(int armor, int damage) override{
        if(armor>0)
        sprite.setTextureRect(IntRect(50*(3- armor),0,50,50));
        if(armor<=0)
            life= false;
        return armor-damage;

    }
    void Desroyed() override{
        if (armor<0)
            life=false;
    }

};


#endif //TEST1_WALL_H
