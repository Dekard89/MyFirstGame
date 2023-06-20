#ifndef TEST1_TANK_H
#define TEST1_TANK_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "MovingObject.h"
#include "IDesrtroyed.h"
#include <string>
#include "Mine.h"


class Tank : public MovingObject,IDesrtroyed,ITakeDamage{
public:
    float armor=1;
    int ammo;
    class Projectile* projectile;

    Tank(float x, float y, int dir, float h, float w, Image &image, float armor) : MovingObject(x, y, dir, h, w, image),
                                                                                   armor(armor) {

    }

    void Desroyed() override{
        if (armor<=0){
            life= false;
            Image deathImage;
            deathImage.loadFromFile("Tanks/DestroyedTank.png");
            texture.loadFromImage(deathImage);
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0,0,100,140));


        }

    }
    void MoveUp(){
        dir=1;
        speed=0.1;
        sprite.setRotation(0);
    }
    void MoveDown(){
        dir=0;
        speed=0.1;
        sprite.setRotation(180);
    }
    void MoveLeft(){
        dir=3;
        speed=0.1;
        sprite.setRotation(270);
    }
    void MoveRight(){
        dir=2;
        speed=0.1;
        sprite.setRotation(90);
    }
    void Shoot(){
        if(ammo>0){
            ammo--;

            Projectile projectile1(GetProjX(),GetProjY(), this->dir);
        }
    }
    float GetProjX(){
        float projX;
        switch (dir) {
            case 0:projX=x+h/2;
                break;
            case 1:projX=x-h/2;
                break;
            case 2:projX=x;
                break;
            case 3:projX=x;
                break;
            
        }
        return projX;
    }
    float GetProjY(){
        float projY;
        switch (dir) {
            case 0:projY=y;
                break;
            case 1:projY=y;
                break;
            case 2:projY=y+h/2;
                break;
            case 3:projY=y-h/2;
                break;

        }
        return projY;
    }
    std::string ShowStats(){

        return "Armor- "+ std::to_string(armor)+"Speed- "+ std::to_string(speed)+"Ammo- "+ std::to_string(ammo);
    }
    float TakeDamage(float armor, float damage) override{
        if (this->getRect().intersects(Mine.getReact))
    }






};


#endif //TEST1_TANK_H
