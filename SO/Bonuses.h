
#ifndef TEST1_BONUSES_H
#define TEST1_BONUSES_H
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "../map.h"
#include <string>


class Bonus: public StaticObject{
private:
    float teleportTimer;
    std::string name;
    float time;
public:
    Bonus(float x, float y, Image &image, std::string name) : StaticObject(x, y, h, w, image,armor,name,damage){
        teleportTimer+=time;
        armor=0;
        if (name=="AmmoBonus")
            sprite.setTextureRect(IntRect(0,50,50,50));
        if (name=="ArmorBonus")
            sprite.setTextureRect(IntRect(0,0,50,50));
        if (name=="SuperBonus")
            sprite.setTextureRect(IntRect(50,0,50,50));
    }
    void Teleport(float teleportX,float teleportY, float time){

        if (teleportTimer>30000){
            teleportTimer=0;
            x=teleportX;
            y=teleportY;
        }

    }

    void SetTeleport() override {
        srand((0));
        float tx;
        float ty;
        tx = 50 + rand() % ((WIDTH_MAP * 50) - 50);
        ty = 50 + rand() % ((HEIGHT_MAP * 50) - 50);

        for (int i = 0; i < WIDTH_MAP; ++i)
            for (int j = 0; j < HEIGHT_MAP; ++j) {
                if (i == tx && j == ty)
                    if (TileMap[i][j] == ' ')
                        Teleport(i * 50, j * 50, time);
            }
    }

    void Desroyed() override{
        life= false;

    }
    int TakeDamage(int armor, int damage) override{
        SetTeleport();
        return armor-damage;

    }



};

#endif //TEST1_BONUSES_H
