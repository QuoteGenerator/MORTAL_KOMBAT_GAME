#include "Game.h"
#include <iostream>
#include <vector>
#include <memory>
#include "RiskyCharacter.h"
#include "MixCharacter.h"
#include "NoRiskyCharacter.h"
#include "Team.h"

Game::Game()
{
    //ctor
}

void Game::printGameMenu(){
    std::cout << "\n\033[32mMORTAL KOMBAT\033[0m"<< std::endl;
    std::cout << "(1) FIGHT" << std::endl;
    std::cout << "(2) CREATE CHARACTER" << std::endl;
    std::cout << "(3) CHARACTERS AND ABILITYS" << std::endl;
    std::cout << "(4) QUIT" << std::endl;
}

void Game::printGameModes(){
    int gameModeInput = 0;
    std::cout << "(1) 1 vs 1" << std::endl;
    std::cout << "(2) 3 vs 3" << std::endl;
    std::cout << "(3) Game Menu" << std::endl;
    std::cout << "Choose: "; std::cin >> gameModeInput;

    if(gameModeInput == 3){
        return;
    } else if(gameModeInput == 1){
        printChooseCharacter("1v1");
    } else if(gameModeInput == 2){
        printChooseCharacter("3v3");
    }

}

void Game::printChooseCharacter(std::string gameMode){
    int whoToFightInput = 0;

    printChooseWhoToFight();
    std::cout << "Choose: "; std::cin >> whoToFightInput;

    if(whoToFightInput == 4){
        return;
    } else if(whoToFightInput == 1){
        Player_VS_Player(gameMode);
    } else if(whoToFightInput == 2){
        Player_VS_NPC(gameMode);
    } else if(whoToFightInput == 3){
        NPC_VS_NPC(gameMode);
    }
}
void Game::printAllCharacters(){
    for(auto c = allCharacters.begin(); c != allCharacters.end(); c++){
        std::cout << "- "
        << "Name: " << (*c)->getName()
        << ", Hp: " << (*c)->getHealthPoints()
        << ", Character Type: " << (*c)->getCharacterTypeName()
        << std::endl;
    }
}

void Game::Player_VS_Player(std::string gameMode){
    std::string chosenCharacter = "";
    bool characterFound = false;
    Team team_1;
    Team team_2;

    printAllCharacters();

    if(gameMode == "1v1"){
        std::cout << "\nPlayer_1";
        while(characterFound == false){
            std::cout << "\nChoose Character (write name): "; std::cin >> chosenCharacter;
            for(auto c = allCharacters.begin(); c != allCharacters.end(); c++){
                if((*c)->getName() == chosenCharacter){
                    //team.addCharacter((*c));
                    std::cout << "CHARACTER GOT FOUND!!!";
                    characterFound = true;
                    break;
                }
            }
            if(characterFound == false){
                std::cout << "CHARACTER NOT FOUND!!!";
            }
        }
    } else if(gameMode == "3v3"){
        for(int i = 0; i < 3; i++){
            characterFound = false;
            while(characterFound == false){
                std::cout << "\nChoose Character (write name): "; std::cin >> chosenCharacter;
                for(auto c = allCharacters.begin(); c != allCharacters.end(); c++){
                    if((*c)->getName() == chosenCharacter){
                        //team.addCharacter((*c));
                        std::cout << "CHARACTER GOT FOUND!!!";
                        characterFound = true;
                        break;
                    }
                }
                if(characterFound == false){
                    std::cout << "CHARACTER NOT FOUND!!!";
                }
            }
        }
    }
}

void Game::Player_VS_NPC(std::string gameMode){
    if(gameMode == "1v1"){

    } else if(gameMode == "3v3"){

    }
}

void Game::NPC_VS_NPC(std::string gameMode){
    if(gameMode == "1v1"){

    } else if(gameMode == "3v3"){

    }
}

void Game::printChooseWhoToFight(){
    std::cout << "(1) Player vs Player" << std::endl;
    std::cout << "(2) Player vs NPC" << std::endl;;
    std::cout << "(3) NPC vs NPC" << std::endl;
    std::cout << "(4) Main Menu" << std::endl;
}

void Game::printCharacterCreation(){
    int createCharacterInput = 0;
    std::cout << "(1) Create Custom Character" << std::endl;
    std::cout << "(2) Main Menu" << std::endl;
    std::cout << "Choose: "; std::cin >> createCharacterInput;

    if(createCharacterInput == 2){
        return;
    }

    if(createCharacterInput == 1){
        std::string name;
        int healthPoints;

        std::cout << "Name: "; std::cin >> name;
        std::cout << "Hp: "; std::cin >> healthPoints;

        std::cout << "\nChoose Character Type\n";

        std::cout << "\n(1) Risky"
                  << "\n    + +40% hit damage"
                  << "\n    + -40% hit chance\n";

        std::cout << "\n(2) Mix"
                  << "\n    + +10% hit damage"
                  << "\n    + +20% hit chance"
                  << "\n    - 20% chance to take self-damage (only if Enemy gets hit!)\n";

        std::cout << "\n(3) NoRisky"
                  << "\n    + 40% less chance to take damage"
                  << "\n    - Much lower chance to hit enemies (-65%)\n";

        std::cout << "\nChoose: "; std::cin >> createCharacterInput;


        if(createCharacterInput == 1){
            addCharacterToGame(std::make_unique<RiskyCharacter>(name, healthPoints));
        }
    }

}

void Game::printCharacters(){
    printAllCharacters();
    std::cout << std::endl;

    std::cout << "\nAll Abilitys: " << std::endl;
    for(auto a = allAblilitys.begin(); a != allAblilitys.end(); a++){


        std::cout << "- "
        << "Name: " << (*a)->getName()
        << ", Damage: " << (*a)->getDamage()
        << ", Hit-Chance: " << (*a)->getHitChance() <<"%"<< std::endl;
    }

    std::cout << "\n(1) Risky"
              << "\n    + +40% hit damage"
              << "\n    + -40% hit chance\n";

    std::cout << "\n(2) Mix"
              << "\n    + +10% hit damage"
              << "\n    + +20% hit chance"
              << "\n    - 20% chance to take self-damage (only if Enemy gets hit!)\n";

    std::cout << "\n(3) NoRisky"
              << "\n    + 40% less chance to take damage"
              << "\n    - Much lower chance to hit enemies (-65%)\n";
}


void Game::addCharacterToGame(std::unique_ptr<Character> newCharacter){
    allCharacters.push_back(std::move(newCharacter));
}

void Game::addAbilityToGame(std::unique_ptr<Ability> newAbility){
    allAblilitys.push_back(std::move(newAbility));
}

void Game::quit(){
    std::cout << "FATALITY!!!";
}
