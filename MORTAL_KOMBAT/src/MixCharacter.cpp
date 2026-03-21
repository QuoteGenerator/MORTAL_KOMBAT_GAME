#include "MixCharacter.h"
#include "Character.h"

MixCharacter::MixCharacter(std::string name, int hp) : Character(name, hp)
{
    //leer
}

std::string MixCharacter::getCharacterTypeName() const{
    return "Mix";
}
