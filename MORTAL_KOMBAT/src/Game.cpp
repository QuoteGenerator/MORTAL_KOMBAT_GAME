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
        << ", Lost Games: " << (*c)->getLostGames()
        << ", Won Games: " << (*c)->getWonGames()
        << std::endl;
    }
}

void Game::startFight(Team& t_1, Team& t_2){
    auto& allCharactersFromTeam_t1 = t_1.getAllCharactersFromThisTeam();
    auto& allCharactersFromTeam_t2 = t_2.getAllCharactersFromThisTeam();

    int chosenAbility = 0;

    std::cout << "\n\n\n\nAll Abilitys: " << std::endl;
    int i = 0;
    for(auto a = allAbilitys.begin(); a != allAbilitys.end(); a++){


        std::cout << "- "
        <<"("<<i<<")"
        << "Name: " << (*a)->getName()
        << ", Damage: " << (*a)->getDamage()
        << ", Hit-Chance: " << (*a)->getHitChance() <<"%"<< std::endl;
        i++;
    }

    std::cout << "\nTeam1:\n";
    for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); c++){
        std::cout << "Choose Ability for: " << (*c)->getName() << std::endl;
        for(int i = 0; i < 2; i++){
            std::cout << "("<<i<<")" << "Ability: "; std::cin >> chosenAbility;
            (*c)->addCharacterAbility(*allAbilitys[chosenAbility], i);
        }
    }
    std::cout << "\nTeam2:\n";
    for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); c++){
        std::cout << "Choose Ability for: " << (*c)->getName() << std::endl;
        for(int i = 0; i < 2; i++){
            std::cout << "("<<i<<")" << "Ability: "; std::cin >> chosenAbility;
            (*c)->addCharacterAbility(*allAbilitys[chosenAbility], i);
        }
    }

    std::cout << "\n\nTeam1::-----------------------------------------------------------------------------------------------------\n";
    for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); c++){
        std::cout << "Name: " << (*c)->getName() << "\t\t"
        << "Hp: " << (*c)->getHealthPoints() << "\t\t"
        << "Class: " << (*c)->getCharacterTypeName() << "\t"
        << "Ability [0]: " << (*c)->getCharacterAbilitys()[0]->getName() << "\t"
        << "Ability [1]: " << (*c)->getCharacterAbilitys()[1]->getName();
        std::cout << std::endl;
    }
    std::cout << "\n\nTeam2:-----------------------------------------------------------------------------------------------------\n";
    for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); c++){
        std::cout << "Name: " << (*c)->getName() << "\t\t"
        << "Hp: " << (*c)->getHealthPoints() << "\t\t"
        << "Class: " << (*c)->getCharacterTypeName() << "\t"
        << "Ability [0]: " << (*c)->getCharacterAbilitys()[0]->getName() << "\t"
        << "Ability [1]: " << (*c)->getCharacterAbilitys()[1]->getName();
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    int combatIndex = 0;
    while(!allCharactersFromTeam_t1.empty() && !allCharactersFromTeam_t2.empty()){
        std::cout << "\n\nTeam1 make your move!\n";
        for(int i = 0; i < allCharactersFromTeam_t1.size(); i++){
            std::cout << allCharactersFromTeam_t1[i]->getName() << " Choose: "; std::cin >> combatIndex;
            allCharactersFromTeam_t2[rand() % allCharactersFromTeam_t2.size()]->decreaseHp(allCharactersFromTeam_t1[i]->dealDamage(combatIndex));
            for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); ){
                if((*c)->getHealthPoints() <= 0){
                    std::cout << "\n\033[33mFrom Team 1: " << (*c)->getName() << " DIED!!!\033[0m\n";
                    for(auto original = allCharacters.begin(); original != allCharacters.end(); original++){
                        if((*original)->getName() == (*c)->getName()){
                            (*original)->increaseLosses();
                            break;
                        }
                    }
                    c = allCharactersFromTeam_t2.erase(c);
                } else {
                    c++;
                }
            }
            if(allCharactersFromTeam_t2.empty()){
                break;
            }
        }
        if(allCharactersFromTeam_t2.empty()){
            break;
        }


        std::cout << "Team2 make your move!\n";
        for(int i = 0; i < allCharactersFromTeam_t2.size(); i++){
            std::cout << allCharactersFromTeam_t2[i]->getName() << " Choose: "; std::cin >> combatIndex;
            allCharactersFromTeam_t1[rand() % allCharactersFromTeam_t1.size()]->decreaseHp(allCharactersFromTeam_t2[i]->dealDamage(combatIndex));

            for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); ){
                if((*c)->getHealthPoints() <= 0){
                    //increase losses
                    std::cout << "\n\033[33mFrom Team 1: " << (*c)->getName() << " DIED!!!\033[0m\n";
                    for(auto original = allCharacters.begin(); original != allCharacters.end(); original++){
                        if((*original)->getName() == (*c)->getName()){
                            (*original)->increaseLosses();
                            break;
                        }
                    }
                    c = allCharactersFromTeam_t1.erase(c);
                } else {
                    c++;
                }

            }
            if(allCharactersFromTeam_t1.empty()){
                break;
            }
        }


        std::cout << "\n\nTeam1:-----------------------------------------------------------------------------------------------------\n";
        for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); c++){
            std::cout << "Name: " << (*c)->getName() << "\t\t"
            << "Hp: " << (*c)->getHealthPoints() << "\t\t"
            << "Class: " << (*c)->getCharacterTypeName() << "\t"
            << "Ability [0]: " << (*c)->getCharacterAbilitys()[0]->getName() << "\t"
            << "Ability [1]: " << (*c)->getCharacterAbilitys()[1]->getName();
            std::cout << std::endl;
        }
        std::cout << "\n\nTeam2:-----------------------------------------------------------------------------------------------------\n";
        for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); c++){
            std::cout << "Name: " << (*c)->getName() << "\t\t"
            << "Hp: " << (*c)->getHealthPoints() << "\t\t"
            << "Class: " << (*c)->getCharacterTypeName() << "\t"
            << "Ability [0]: " << (*c)->getCharacterAbilitys()[0]->getName() << "\t"
            << "Ability [1]: " << (*c)->getCharacterAbilitys()[1]->getName();
            std::cout << std::endl;
        }
    }

    if(allCharactersFromTeam_t1.empty() && allCharactersFromTeam_t2.empty()){
        std::cout << "\n\n!!!IT IS A DRAW!!!\n\n";
    } else if(allCharactersFromTeam_t1.empty()){
        std::cout << "\n\n!!!TEAM 2 WINS!!!\n\n";
        for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); ++c){
            for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                if((*original)->getName() == (*c)->getName()){
                    (*original)->increaseWins();
                    break;
                }
            }
        }
    } else if(allCharactersFromTeam_t2.empty()){
        std::cout << "\n\n!!!TEAM 1 WINS!!!\n\n";
        for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); ++c){
            for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                if((*original)->getName() == (*c)->getName()){
                    (*original)->increaseWins();
                    break;
                }
            }
        }
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
                    team_1.addCharacterToTeam(*(*c));
                    std::cout << "CHARACTER GOT FOUND!!!\n";
                    characterFound = true;
                    break;
                }
            }
            if(characterFound == false){
                std::cout << "CHARACTER NOT FOUND!!!\n";
            }
        }
        characterFound = false;
        std::cout << "\nPlayer_2";
        while(characterFound == false){
            std::cout << "\nChoose Character (write name): "; std::cin >> chosenCharacter;
            for(auto c = allCharacters.begin(); c != allCharacters.end(); c++){
                if((*c)->getName() == chosenCharacter){
                    team_2.addCharacterToTeam(*(*c));
                    std::cout << "CHARACTER GOT FOUND!!!";
                    characterFound = true;
                    break;
                }
            }
            if(characterFound == false){
                std::cout << "CHARACTER NOT FOUND!!!";
            }
        }


    startFight(team_1, team_2);




} else if(gameMode == "3v3"){
    std::cout << "\nPlayer_1";
    for(int i = 0; i < 3; i++){
        characterFound = false;
        while(characterFound == false){
            std::cout << "\nChoose Character (write name): ";
            std::cin >> chosenCharacter;

            for(auto c = allCharacters.begin(); c != allCharacters.end(); c++){
                if((*c)->getName() == chosenCharacter){
                    team_1.addCharacterToTeam(*(*c));
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

        std::cout << "\nPlayer_2";
        for(int i = 0; i < 3; i++){
            characterFound = false;
            while(characterFound == false){
                std::cout << "\nChoose Character (write name): ";
                std::cin >> chosenCharacter;

                for(auto c = allCharacters.begin(); c != allCharacters.end(); c++){
                    if((*c)->getName() == chosenCharacter){
                        team_2.addCharacterToTeam(*(*c));
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
        startFight(team_1, team_2);
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
    std::cout << "(2) Player vs NPC" << std::endl;
    std::cout << "(3) NPC vs NPC" << std::endl;
    std::cout << "(4) Main Menu" << std::endl;
}

void Game::printCharacterCreation(){
    int createCharacterInput = 0;
    bool givenNameDoesExist = false;
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

        bool givenNameDoesExist = true;
        while(givenNameDoesExist == true){
            givenNameDoesExist = false;

            for(auto& c : allCharacters){
                if(c->getName() == name){
                    givenNameDoesExist = true;
                }
            }

            if(givenNameDoesExist){
                std::cout << "Name already exists!: ";
                std::cout << "Enter new Name: "; std::cin >> name;
            }
        }

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
        if(createCharacterInput == 2){
            addCharacterToGame(std::make_unique<MixCharacter>(name, healthPoints));
        }
        if(createCharacterInput == 3){
            addCharacterToGame(std::make_unique<NoRiskyCharacter>(name, healthPoints));
        }
    }

}

void Game::printCharacters(){
    std::cout << "\nAll Characters: \n";
    printAllCharacters();

    std::cout << std::endl;

    std::cout << "\nAll Abilitys: " << std::endl;
    for(auto a = allAbilitys.begin(); a != allAbilitys.end(); a++){


        std::cout << "- "
        << "Name: " << (*a)->getName()
        << ", Damage: " << (*a)->getDamage()
        << ", Hit-Chance: " << (*a)->getHitChance() <<"%"<< std::endl;
    }

    std::cout << "\nAll Classes: ";

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
    allAbilitys.push_back(std::move(newAbility));
}

void Game::quit(){
    std::cout << "FATALITY!!!";
}
