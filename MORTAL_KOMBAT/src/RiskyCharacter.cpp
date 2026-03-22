#include "RiskyCharacter.h"
#include "Character.h"

RiskyCharacter::RiskyCharacter(std::string name, int hp) : Character(name, hp)
{
    //leer
}

std::string RiskyCharacter::getCharacterTypeName() const{
    return "Risky";
}



std::unique_ptr<Character> RiskyCharacter::clone(){
    auto copiedCharacter = std::make_unique<RiskyCharacter>(getName(), getHealthPoints());

    auto& abilities = getCharacterAbilitys();
    for (int i = 0; i < 2; i++) {
        if (abilities[i]) {
            copiedCharacter->addCharacterAbility(*abilities[i], i);
        }
    }

    return copiedCharacter;
}


int RiskyCharacter::dealDamage(int index){
       if(index < 0 || index >= getCharacterAbilitys().size() || !getCharacterAbilitys()[index]){
        return 0;
    }
    if(rand() % 101 < getCharacterAbilitys()[index]->getHitChance() * 0.5){
        return getCharacterAbilitys()[index]->getDamage()*1.4;
    } else {
        return 0;
    }
}
