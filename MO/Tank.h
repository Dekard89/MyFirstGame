#ifndef TEST1_TANK_H
#define TEST1_TANK_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "MovingObject.h"
#include "../IDesrtroyed.h"
#include <string>
#include "../SO/Mine.h"
#include "../map.h"


class Tank : public MovingObject{
protected:
    int armor=1;
    int ammo;
    int countOfMine;
    std::string name;



public:


    Tank(float x, float y, float h, float w, Image &image, int dir,std::string name) : MovingObject(x, y, h, w, image,dir){
        image.createMaskFromColor(Color(55,62,72));
        h=75;
        w=50;

}

    void Desroyed() override {
        if (armor <= 0) {
            life = false;
            Image deathImage;
            deathImage.loadFromFile("Tanks/DestroyedTank.png");
            texture.loadFromImage(deathImage);
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0, 0, 50, 75));


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
    Projectile Shoot(float x, float y){

            Projectile projectile(GetProjX(),GetProjY(), this->dir);
            ammo--;
            isShoting= false;
            return projectile;
    }
    Mine TrapSet(float x,float y){
            Mine mine(GetMineX(),GetMineY());
            isPlanting= false;
            countOfMine--;
            return mine;

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
    float GetMineX(){
        float mineX;
        switch (dir) {
            case 0:mineX=x-h/2;
                break;
            case 1:mineX=x+h/2;
                break;
            case 2:mineX=x;
                break;
            case 3:mineX=x;
                break;

        }
        return mineX;
    }
    float GetMineY() {
        float mineY;
        switch (dir) {
            case 0:
                mineY = y;
                break;
            case 1:
                mineY = y;
                break;
            case 2:
                mineY = y - h / 2;
                break;
            case 3:
                mineY = y + h / 2;
                break;

        }
        return mineY;
    }

    void Control(){
        if(name=="Player"){
            if(Keyboard::isKeyPressed(Keyboard::W)) {
                MoveUp();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                MoveDown();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                MoveRight();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                MoveLeft();
                getPlayerCoordinateForView(getX(), getY());
            }
            if (Keyboard::isKeyPressed(Keyboard::Q)) {
                isShoting= true;
                Shoot(x,y);
            }
            if (Keyboard::isKeyPressed(Keyboard::E)){
                isPlanting=true;
                TrapSet(x,y);

            }


        }
    }
    void interactionWithMap()
    {

        for (int i = y / 50; i < (y + h) / 50; i++)
            for (int j = x / 50; j<(x + w) / 50; j++) {
                if (i < 0 || j < 0) {
                    i = 0;
                    j = 0;

                    if (TileMap[i][j] == '0' || TileMap[i][j] == 'w') {
                        if (bustY > 0) {
                            y = i * 50 - h;
                        }
                        if (bustY < 0) {
                            y = i * 50 + 50;
                        }
                        if (bustX > 0) {
                            x = j * 50 - w;
                        }
                        if (bustX < 0) {
                            x = j * 50 + 50;
                        }

                    }
                }
            }
    }

    void Update(float time) override {
        switch (dir) {
            case 0:
                bustX = 0;
                bustY = speed;
                break;
            case 1:
                bustX = 0;
                bustY = -speed;
                break;
            case 2:
                bustX = speed;
                bustY = 0;
                break;
            case 3:
                bustX = -speed;
                bustY = 0;
                break;
        }
        x += bustX * time;
        y += bustY * time;
        interactionWithMap();
        speed = 0;
        Control();
        sprite.setPosition(x, y);
        }


    int TakeDamage(int armor, int damage) override{
        return armor-damage;
    }

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        Tank::armor = armor;
    }

    void setAmmo(int ammo) {
        Tank::ammo = ammo;
    }

    void setCountOfMine(int countOfMine) {
        Tank::countOfMine = countOfMine;
    }

    int getAmmo() const {
        return ammo;
    }

    int getCountOfMine() const {
        return countOfMine;
    }


};


#endif //TEST1_TANK_H
