#include "Ability.h"

Ability::Ability(std::string givenName, int givenDamage, float givenHitChance)
{
    name = givenName;
    damage = givenDamage;
    hitChance = givenHitChance;
}

std::string Ability::getName(){
    return name;
}
int Ability::getDamage(){
    return damage;
}
float Ability::getHitChance(){
    return hitChance;
}


std::unique_ptr<Ability> Ability::clone(){
    return std::make_unique<Ability>(*this);
}
