
#ifndef TEST1_IDESRTROYED_H
#define TEST1_IDESRTROYED_H
#include "Projectile.h"
#include "Tank.h"

class IDesrtroyed {
   virtual void Desroyed()=0;

};

class ITakeDamage{
    float TakeDamage(float armor,float damage){
        return armor-damage;

    }
};

#endif //TEST1_IDESRTROYED_H
