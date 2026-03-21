#include "NoRiskyCharacter.h"
#include "Character.h"

NoRiskyCharacter::NoRiskyCharacter(std::string name, int hp) : Character(name, hp)
{
    //leer
}

std::string NoRiskyCharacter::getCharacterTypeName() const{
    return "NoRisky";
}

