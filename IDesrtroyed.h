
#ifndef TEST1_IDESRTROYED_H
#define TEST1_IDESRTROYED_H
#include "MO/Projectile.h"
#include "MO/Tank.h"

class IDesrtroyed {
public:
   virtual void Desroyed()=0;

};

class ITakeDamage{
public:
    virtual int TakeDamage(int armor,int damage){
        return armor-damage;

    }
};

#endif //TEST1_IDESRTROYED_H
