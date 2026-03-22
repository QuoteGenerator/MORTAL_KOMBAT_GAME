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



int main()
{
    Game game;
    srand(time(nullptr));

    game.addCharacterToGame(std::make_unique<RiskyCharacter>("Goro", 105));
    game.addCharacterToGame(std::make_unique<MixCharacter>("Sonya", 100));
    game.addCharacterToGame(std::make_unique<NoRiskyCharacter>("Scorpion", 90));

    game.addAbilityToGame(std::make_unique<Ability>("Uppercut", 30, 50));
    game.addAbilityToGame(std::make_unique<Ability>("Leg Kick", 15, 90));
    game.addAbilityToGame(std::make_unique<Ability>("Double Hit (2x Attack)", 10, 80));

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
