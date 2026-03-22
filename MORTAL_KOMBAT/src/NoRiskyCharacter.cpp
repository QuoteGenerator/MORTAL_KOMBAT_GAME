#include "NoRiskyCharacter.h"
#include "Character.h"

NoRiskyCharacter::NoRiskyCharacter(std::string name, int hp) : Character(name, hp)
{
    //leer
}

std::string NoRiskyCharacter::getCharacterTypeName() const{
    return "NoRisky";
}

std::unique_ptr<Character> NoRiskyCharacter::clone(){
    auto copiedCharacter = std::make_unique<NoRiskyCharacter>(getName(), getHealthPoints());

    auto& abilities = getCharacterAbilitys();
    for (int i = 0; i < 2; i++) {
        if (abilities[i]) {
            copiedCharacter->addCharacterAbility(*abilities[i], i);
        }
    }

    return copiedCharacter;
}


int NoRiskyCharacter::dealDamage(int index){
   if(index < 0 || index >= getCharacterAbilitys().size() || !getCharacterAbilitys()[index]){
        return 0;
    }
    return getCharacterAbilitys()[index]->getDamage();
}
