
#ifndef TEST1_MINE_H
#define TEST1_MINE_H
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "IDesrtroyed.h"
#include "Tank.h"

using namespace sf;


class Mine:StaticObject,IDesrtroyed {
private:
    float damage=1;
public:
    Mine(float x, float y, float h, float w, Image &image, float damage) : StaticObject(x, y, h, w, image){
        image.loadFromFile("Source/Mine.png");
    }
    void Desroyed() override{
        if (this->getRect().intersects(Tank().getRect())){}
    }


};


#endif //TEST1_MINE_H
