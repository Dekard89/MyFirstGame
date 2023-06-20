
#ifndef TEST1_TANKS_H
#define TEST1_TANKS_H

#include <SFML/Graphics.hpp>
#include "Tank.h"
#include <string>

using namespace sf;

class HardTank : Tank{
private:
    int factorOfSpeed=1;
    int factorOfArmor=4;
    std::string name;
    std::string path="Tanks/hardTank.png";
public:
    HardTank(std::string name,float x,float y) : Tank(x, y,dir, h,w, image, armor){
        speed*=factorOfSpeed;
        armor*=factorOfArmor;
        image.loadFromFile(path);
        h=144;
        w=100;
        ammo=25;
    }

    int getFactorOfSpeed() const {
        return factorOfSpeed;
    }



};
class  SemihardTank : Tank {
private:
    int factorOfSpeed = 2;
    int factorOfArmor = 3;
    std::string name;
    std::string path = "Tanks/semihardTank.png";
public:
    SemihardTank(std::string name,float x,float y) : Tank(x, y, dir,h, w,image,armor){
        speed*=factorOfSpeed;
        armor*=factorOfArmor;
        image.loadFromFile(path);
        h=144;
        w=90;
        ammo=20;
    }

    int getFactorOfSpeed() const {
        return factorOfSpeed;
    }

};
class  MediumTank : Tank {
private:
    int factorOfSpeed = 3;
    int factorOfArmor = 2;
    std::string name;
    std::string path = "Tanks/mediumTank.png";
public:
    MediumTank(std::string name,float x,float y) : Tank(x, y, dir,h, w,image,armor){
        speed*=factorOfSpeed;
        armor*=factorOfArmor;
        image.loadFromFile(path);
        h=137;
        w=90;
        ammo=20;
    }

    int getFactorOfSpeed() const {
        return factorOfSpeed;
    }
};
class  LightTank : Tank {
private:
    int factorOfSpeed = 4;
    int factorOfArmor = 1;
    std::string name;
    std::string path = "Tanks/lightTank.png";
public:
    LightTank(std::string name,float x,float y) : Tank(x, y, dir,h, w,image,armor){
        speed*=factorOfSpeed;
        armor*=factorOfArmor;
        image.loadFromFile(path);
        h=134;
        w=80;
        ammo=15;
    }

    int getFactorOfSpeed() const {
        return factorOfSpeed;
    }
};

#endif //TEST1_TANKS_H
