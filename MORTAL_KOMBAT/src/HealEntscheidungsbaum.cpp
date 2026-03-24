#include "HealEntscheidungsbaum.h"
#include <iostream>

HealEntscheidungsbaum::HealEntscheidungsbaum(std::string newName, std::string description) : Entscheidungsbaum(newName, description)
{
    //ctor
}


std::unique_ptr<Entscheidungsbaum> HealEntscheidungsbaum::clone(){
    auto copiedEntscheidungsbaum = std::make_unique<HealEntscheidungsbaum>(getName(), getDescription());

    return copiedEntscheidungsbaum;
}

void HealEntscheidungsbaum::afterAttack(Character& myself, std::vector<std::unique_ptr<Character>>& enemyTeam){

    if((myself.getHealthPoints() < 20) && (rand() % 101 < 20)){
        myself.increaseHp(20);
        std::cout << "\e[1;34mQUAN CHI HEALED YOU + 20hp ( "<< myself.getName() << " ) !\033[0m";
    }
}
