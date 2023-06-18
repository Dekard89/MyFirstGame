
#ifndef TEST1_MOVINGOBJECT_H
#define TEST1_MOVINGOBJECT_H

#include <SFML/Graphics.hpp>


using namespace sf;


class MovingObject {
public:
 float x;
 float y;
 float bustX;
 float bustY;
 int dir;
 float speed=0;
 float h;
 float w;
bool life= true;
Image image;
Texture texture;
Sprite sprite;

    MovingObject(float x,float y, int dir,float h,float w, Image &image) {
        this->x=x;
        this->y=y;
        this->w=w;
        this->h=h;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w/2,h/2);

    }

    void Update(float time) {
        switch (dir) {
            case 0:
                bustX=0;
                bustY=speed;
                break;
            case 1:
                bustX=0;
                bustY=-speed;
                break;
            case 2:
                bustX=speed;
                bustY=0;
                break;
            case 3:
                bustX=-speed;
                bustY=0;
                break;
        }
        x+=bustX*time;
        y+=bustY*time;
        speed=0;
        sprite.setPosition(x,y);

    };
    FloatRect getRect(){
        return FloatRect (x,y,w,h);
    }
};


#endif //TEST1_MOVINGOBJECT_H
