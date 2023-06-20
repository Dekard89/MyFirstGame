
#ifndef TEST1_STATICOBJECT_H
#define TEST1_STATICOBJECT_H
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject {
public:
    float x;
    float y;
    float h;
    float w;
    std::string path;
    bool life = true;
    Image image;
    Texture texture;
    Sprite sprite;

    FloatRect getRect() {
        return FloatRect(x, y, w, h);

    }
    StaticObject(float x,float y,float h,float w,Image &image) {
        this->x=x;
        this->y=y;
        this->h=h;
        this->w=w;
        image.loadFromFile(path);
        texture.loadFromImage(image);
        sprite.setTexture(texture);


    }


};
#endif //TEST1_STATICOBJECT_H
