#include "RageEntscheidungsbaum.h"
#include <iostream>

RageEntscheidungsbaum::RageEntscheidungsbaum(std::string newName, std::string description) : Entscheidungsbaum(newName, description)
{
    //ctor
}


std::unique_ptr<Entscheidungsbaum> RageEntscheidungsbaum::clone(){
    auto copiedEntscheidungsbaum = std::make_unique<RageEntscheidungsbaum>(getName(), getDescription());

    return copiedEntscheidungsbaum;
}


void RageEntscheidungsbaum::afterAttack(Character& myself, std::vector<std::unique_ptr<Character>>& enemyTeam){

    int health = 0;
    int spot = 0;
    int i = 0;

    if(rand() % 101 < 10){
        for(auto e = enemyTeam.begin(); e != enemyTeam.end(); e++){
            if(health < (*e)->getHealthPoints()){
                spot = i;
                health = (*e)->getHealthPoints();
            }
            i++;
        }
        enemyTeam[spot]->decreaseHp(10);

        std::cout << "YOU " << "("<< myself.getName() << ")" << " ARE IN RAGE AND DAMAGE (-10 hp) " << enemyTeam[spot]->getName() << std::endl;
    }

}
