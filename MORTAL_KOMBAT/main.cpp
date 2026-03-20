#include <iostream>
#include <memory>
#include <vector>
#include "Game.h"
#include "Character.h"
#include "RiskyCharacter.h"
#include "Ability.h"
#include "Team.h"


int main()
{
    Game game;

    game.addCharacterToGame(std::make_unique<RiskyCharacter>("Sub-Zero", 100));
    game.addCharacterToGame(std::make_unique<RiskyCharacter>("Scorpion", 90));

    game.addAbilityToGame(std::make_unique<Ability>("Uppercut", 30, 50));
    game.addAbilityToGame(std::make_unique<Ability>("Leg Kick", 10, 90));

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
