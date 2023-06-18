
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
    bool life= true;
    Image image;
    Texture texture;
    Sprite sprite;
    FloatRect getRect(){
        return FloatRect (x,y,w,h);

};


#endif //TEST1_STATICOBJECT_H
