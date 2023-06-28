
#ifndef TEST1_TANKS_H
#define TEST1_TANKS_H

#include <SFML/Graphics.hpp>
#include "Tank.h"
#include <string>

using namespace sf;

class HardTank : public Tank{
private:
    int factorOfSpeed=1;
    int factorOfArmor=4;

public:
    HardTank(std::string name, float x, float y) : Tank(x, y, h, w, image,dir,name){

    speed*=factorOfSpeed;
        armor*=factorOfArmor;
        ammo=25;
        countOfMine=2;
        image.loadFromFile("Tanks/hardTank.png");
    }

};
class  SemihardTank : public Tank {
protected:
    int factorOfSpeed = 2;
    int factorOfArmor = 3;
public:
    SemihardTank(std::string name,float x,float y) : Tank(x, y, h, w, image,dir,name){
        speed*=factorOfSpeed;
        armor*=factorOfArmor;
        ammo=20;
        countOfMine=3;
        image.loadFromFile("Tanks/semihardTank.png");
    }


};
class  MediumTank : public Tank {
private:
    int factorOfSpeed = 3;
    int factorOfArmor = 2;
public:
    MediumTank(std::string name,float x,float y) :Tank(x, y, h, w, image,dir,name){
        speed*=factorOfSpeed;
        armor*=factorOfArmor;
        ammo=20;
        countOfMine=4;
        image.loadFromFile("Tanks/mediumTank.png");
    }

};
class  LightTank : public Tank {
private:
    int factorOfSpeed = 4;
    int factorOfArmor = 1;

public:
    LightTank(std::string name,float x,float y) :Tank(x, y, h, w, image,dir,name){
        speed*=factorOfSpeed;
        armor*=factorOfArmor;
        ammo=15;
        countOfMine=5;
        image.loadFromFile("Tanks/lightTank.png");
    }

};

#endif //TEST1_TANKS_H
