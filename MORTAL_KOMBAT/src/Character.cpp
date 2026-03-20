#include "Character.h"


Character::Character(std::string givenName, int givenHealthPoints){

    name = givenName;
    healthPoints = givenHealthPoints;

}

Character::~Character()
{
    //dtor
}


std::string Character::getName(){
    return name;
}
int Character::getHealthPoints(){
    return healthPoints;
}

