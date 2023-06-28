
#ifndef TEST1_STATICOBJECT_H
#define TEST1_STATICOBJECT_H
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticObject : public ITakeDamage,IDesrtroyed{
protected:
    float x;
    float y;
    float h;
    float w;
    std::string name;
    bool life = true;
    Image image;
    Texture texture;
    Sprite sprite;
    int armor;
    int damage;
public:

    FloatRect getRect() {
        return FloatRect(x, y, w, h);

    }
    StaticObject(float x,float y,float h,float w,Image &image,int armor,std::string name,int damage) {
        x=x;
        y=y;
        w=w;
        h=h;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0,0,w,h));

    }

    virtual void SetTeleport(){

    }

    int getArmor() const {
        return armor;
    }

    bool isLife() const {
        return life;
    }
    int TakeDamage(int armor, int damage) override{
        return armor-damage;

    }
    void Desroyed() override{

    }

    const std::string &getName() const {
        return name;
    }

    int getDamage() const {
        return damage;
    }

    const Sprite &getSprite() const {
        return sprite;
    }

    void setSprite(const Sprite &sprite) {
        StaticObject::sprite = sprite;
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }


};
#endif //TEST1_STATICOBJECT_H
