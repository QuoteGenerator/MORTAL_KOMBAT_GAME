#include "RiskyCharacter.h"
#include "Character.h"

RiskyCharacter::RiskyCharacter(std::string name, int hp) : Character(name, hp)
{
    //leer
}

std::string RiskyCharacter::getCharacterTypeName() const{
    return "Risky";
}
