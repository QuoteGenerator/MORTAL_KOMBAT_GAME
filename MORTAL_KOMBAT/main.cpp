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

    game.addEntscheidungsbaumToGame(std::make_unique<RageEntscheidungsbaum>("Rage", "Attacks_the_enemy_with_most_Hp,_sometimes!"));
    game.addEntscheidungsbaumToGame(std::make_unique<HealEntscheidungsbaum>("Heal", "Heals_by_20%,_when_under_20%_hp,_sometimes!"));


    int menuInput = 0;
    while(1){
        game.printGameMenu();
        std::cout << "Choose: ";
        std::cin >> menuInput;
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
