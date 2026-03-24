#include "Character.h"
#include "Ability.h"
#include "Entscheidungsbaum.h"

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


int Character::getLostGames(){
    return lostGames;
}

int Character::getWonGames(){
    return wonGames;
}

void Character::increaseHp(int healingAmount){
    healthPoints += healingAmount;
}

void Character::decreaseHp(int dealedDamage){
    healthPoints -= dealedDamage;
}


std::array<std::unique_ptr<Ability>, 2>& Character::getCharacterAbilitys(){
    return abilitys;
}

void Character::addCharacterAbility(Ability& newAbility, int index){
    abilitys[index] = newAbility.clone();
}

void Character::addCharacterEntscheidungsbaum(Entscheidungsbaum& newEntscheidungsbaum){
    meinEntscheidungsbaum[0] = newEntscheidungsbaum.clone();
}

void Character::increaseLosses(){
    lostGames += 1;
}
void Character::increaseWins(){
    wonGames += 1;
}


Entscheidungsbaum* Character::getEntscheidungsbaum(){
    return meinEntscheidungsbaum[0].get(); //mit get indirekt zugriff geben, da Pointer übergeben wird!!!!!
}
