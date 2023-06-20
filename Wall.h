
#ifndef TEST1_WALL_H
#define TEST1_WALL_H
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "IDesrtroyed.h"
#include <string>
#include "Projectile.h"

using namespace sf;

class Wall:StaticObject,ITakeDamage,IDesrtroyed {
private:
    float armor=3;
    std::string path;

public:
    Wall(float x, float y, float h, float w, Image &image, float armor) : StaticObject(x, y, h, w, image){
        path="Source/walls.png";
        w=50;
        h=50;
        image.loadFromFile(path);
        sprite.setTextureRect(IntRect(0,0,w,h));

    }
    float TakeDamage(float armor, float damage) override{

        float currentFrame=3;
        sprite.setTextureRect(IntRect(50*int(currentFrame-armor),0,50,50));

    }

};


#endif //TEST1_WALL_H
