

#ifndef TEST1_ENEMYTANK_H
#define TEST1_ENEMYTANK_H
#include <SFML/Graphics.hpp>
#include "Projectile.h"
#include "MovingObject.h"
#include "../IDesrtroyed.h"
#include <string>
#include "../SO/Mine.h"
#include "../map.h"

using namespace sf;

class EnemyTank :public MovingObject{
protected:
    int armor=1;
    int countOfMine;
    std::string name;

    void  Desroyed() override {
        if (armor <= 0) {
            life = false;
            Image deathImage;
            deathImage.loadFromFile("Tanks/DestroyedTank.png");
            texture.loadFromImage(deathImage);
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0, 0, 50, 75));
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
    float GetProjY() {
        float projY;
        switch (dir) {
            case 0:
                projY = y;
                break;
            case 1:
                projY = y;
                break;
            case 2:
                projY = y + h / 2;
                break;
            case 3:
                projY = y - h / 2;
                break;
        }
        return projY;
    }
    void interactionWithMapForEnemy()
    {

        for (int i = y / 50; i < (y + h) / 50; i++)
            for (int j = x / 50; j<(x + w) / 50; j++)
            {
                if (TileMap[i][j] == '0'||TileMap[i][j]=='w') {
                    if (bustY > 0) {
                        y = i * 50 - h;
                        if(x<(WIDTH_MAP/2)*50){sprite.setRotation(90);}
                        if(x>(WIDTH_MAP/2)*50){sprite.setRotation(270);}
                    }
                    if (bustY < 0) {
                        y = i * 50 +50;
                        sprite.scale(1,-1);
                    }
                    if (bustX > 0) {
                        x = j * 50 - w;
                        sprite.setRotation(180);
                    }
                    if (bustX < 0) {
                        x = j * 50 + 50;
                        sprite.setRotation(180);

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
        interactionWithMapForEnemy();
        EnemyShoot(time);

        sprite.setPosition(x, y);
    }


    void EnemyShoot(float time){
        float shootTimer;
        shootTimer+=time;
        if(shootTimer>1000){
            shootTimer=0;
            Shoot(x,y);
            isShoting= false;
        }
    }

    Projectile Shoot(float x, float y) {

        Projectile projectile(GetProjX(), GetProjY(), this->dir);
        isShoting = false;
        return projectile;
    }
    int TakeDamage(int armor, int damage) override{
        return armor-damage;
    }

    int getArmor() const {
        return armor;
    }



};


#endif //TEST1_ENEMYTANK_H
