
#ifndef TEST1_MINE_H
#define TEST1_MINE_H
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "../IDesrtroyed.h"
#include "../MO/Tank.h"

using namespace sf;


class Mine: public StaticObject {
private:
    float damage=1;
public:
    Mine(float x, float y) : StaticObject(x, y, h, w, image,armor,name,damage){
        image.loadFromFile("Source/Mine.png");
        name="Mine";

    }
    void Desroyed() override{
        life= false;
        sprite.setTextureRect(IntRect(0,50,w,h));
    }

    float getDamage() const {
        return damage;
    }


};


#endif //TEST1_MINE_H
