#include "MixCharacter.h"
#include "Character.h"
#include "Ability.h"
#include <iostream>

MixCharacter::MixCharacter(std::string name, int hp) : Character(name, hp)
{
    //leer
}

std::string MixCharacter::getCharacterTypeName() const{
    return "Mix";
}

std::unique_ptr<Character> MixCharacter::clone(){
    auto copiedCharacter = std::make_unique<MixCharacter>(getName(), getHealthPoints());

    auto& abilities = getCharacterAbilitys();
    for (int i = 0; i < 2; i++) {
        if (abilities[i]) {
            copiedCharacter->addCharacterAbility(*abilities[i], i);
        }
    }

    return copiedCharacter;
}


int MixCharacter::dealDamage(int index){
    if(index < 0 || index >= getCharacterAbilitys().size() || !getCharacterAbilitys()[index]){
        return 0;
    }
    if(rand() % 101 < getCharacterAbilitys()[index]->getHitChance() * 1.2){
        return getCharacterAbilitys()[index]->getDamage()*1.1;
    } else {
        return 0;
    }
}
