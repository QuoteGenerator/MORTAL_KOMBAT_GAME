#include <iostream>
#include <memory>
#include <vector>
#include <time.h>
#include "Game.h"
#include "Character.h"
#include "RiskyCharacter.h"
#include "NoRiskyCharacter.h"
#include "MixCharacter.h"
#include "Ability.h"
#include "Team.h"
#include "RageEntscheidungsbaum.h"
#include "HealEntscheidungsbaum.h"



int main()
{
    Game game;
    srand(time(nullptr));

    game.addCharacterToGame(std::make_unique<RiskyCharacter>("Goro", 105));
    game.addCharacterToGame(std::make_unique<MixCharacter>("Sonya", 100));
    game.addCharacterToGame(std::make_unique<NoRiskyCharacter>("Scorpion", 90));

    game.addAbilityToGame(std::make_unique<Ability>("Uppercut", 30, 50));
    game.addAbilityToGame(std::make_unique<Ability>("Leg Kick", 15, 90));
    game.addAbilityToGame(std::make_unique<Ability>("Punch", 10, 100));

    game.addEntscheidungsbaumToGame(std::make_unique<RageEntscheidungsbaum>("Rage", "10% chance, to make an extra -10hp on the enemy with most hp!"));
    game.addEntscheidungsbaumToGame(std::make_unique<HealEntscheidungsbaum>("Heal", "20% chance, to heal when under 20% Hp"));


    int menuInput = 0;
    while(1){
        game.printGameMenu();
        std::cout << "Choose: ";
        while(true){
            if(!(std::cin >> menuInput)){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "WRONG INPUT!\n";
                continue;
            }
            if(menuInput > 0 && menuInput < 5){
                break;
            }
            std::cout << "Out of range!\nChoose 1,2,3 or 4!: ";
        }
        switch(menuInput){
            case 1:
                game.printGameModes();
            break;
            case 2:
                game.printCharacterCreation();
            break;
            case 3:
                game.printCharacters();
            break;
            case 4:
                game.quit();
                return 0;
            break;

        }
    }
    return 0;
}
