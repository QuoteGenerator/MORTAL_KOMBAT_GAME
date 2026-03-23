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
    //Empty!!!!!!
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

    while(true){
        std::cout << "Choose: ";
        if(!(std::cin >> gameModeInput)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input!\n";
            continue;
        }

        if(gameModeInput >= 1 && gameModeInput <= 3){
            break;
        }

        std::cout << "Invalid choice!\n";
    }

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

    while(true){
        std::cout << "Choose: ";
        if(!(std::cin >> whoToFightInput)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input!\n";
            continue;
        }

        if(whoToFightInput >= 1 && whoToFightInput <= 4){
            break;
        }

        std::cout << "Invalid choice!\n";
    }

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

void Game::startFight(Team& t_1, Team& t_2, bool npc_1, bool npc_2){
    auto& allCharactersFromTeam_t1 = t_1.getAllCharactersFromThisTeam();
    auto& allCharactersFromTeam_t2 = t_2.getAllCharactersFromThisTeam();

    int chosenAbility = 0;

    std::cout << "\n\n\n\nAll Abilitys: " << std::endl;
    printAllAbilitys();

    std::cout << "\nTeam1:";
    if(npc_1){ std::cout << " [NPC_1]:"; }

    for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); c++){
        std::cout << "\nChoose Ability for: " << (*c)->getName() << std::endl;
        for(int i = 0; i < 2; i++){
            if(npc_1){
                chosenAbility = rand() % allAbilitys.size();
                std::cout << "(" << i << ") Ability: " << chosenAbility << " [NPC]\n";
                (*c)->addCharacterAbility(*allAbilitys[chosenAbility], i);
            } else {
                while(true){
                    std::cout << "(" << i << ") Ability: ";

                    if(!(std::cin >> chosenAbility)){
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input! Enter a number.\n";
                        continue;
                    }

                    if(chosenAbility >= 0 && chosenAbility < allAbilitys.size()){
                        (*c)->addCharacterAbility(*allAbilitys[chosenAbility], i);
                        break;
                    }

                    std::cout << "Invalid choice! Choose between 0 and " << allAbilitys.size()-1 << "\n";
                }
            }
        }
    }

    std::cout << "\nTeam2:";
    if(npc_2){ std::cout << " [NPC_2]:"; }

    for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); c++){
        std::cout << "\nChoose Ability for: " << (*c)->getName() << std::endl;
        for(int i = 0; i < 2; i++){
            if(npc_2){
                chosenAbility = rand() % allAbilitys.size();
                std::cout << "(" << i << ") Ability: " << chosenAbility << " [NPC]\n";
                (*c)->addCharacterAbility(*allAbilitys[chosenAbility], i);
            } else {
                while(true){
                    std::cout << "(" << i << ") Ability: ";

                    if(!(std::cin >> chosenAbility)){
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input! Enter a number.\n";
                        continue;
                    }

                    if(chosenAbility >= 0 && chosenAbility < allAbilitys.size()){
                        (*c)->addCharacterAbility(*allAbilitys[chosenAbility], i);
                        break;
                    }

                    std::cout << "Invalid choice! Choose between 0 and " << allAbilitys.size()-1 << "\n";
                }
            }
        }
    }

    printCharactersFromTeams(allCharactersFromTeam_t1, allCharactersFromTeam_t2);

    std::cout << std::endl;
    std::cout << std::endl;

    int combatIndex = 0;
    int index = 0;
    int damageAmount = 0;

    std::vector<std::string> alreadyLost;

    while(!allCharactersFromTeam_t1.empty() && !allCharactersFromTeam_t2.empty()){

        std::cout << "\n\nTeam1 make your move!\n";
        for(int i = 0; i < allCharactersFromTeam_t1.size(); i++){
            if(npc_1){
                combatIndex = rand() % 2;
                std::cout << allCharactersFromTeam_t1[i]->getName() << " Choose: " << combatIndex << " [NPC]\n";
            } else {
                while(true){
                    std::cout << allCharactersFromTeam_t1[i]->getName() << " Choose: ";

                    if(!(std::cin >> combatIndex)){
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input!\n";
                        continue;
                    }

                    if(combatIndex >= 0 && combatIndex < 2){
                        break;
                    }

                    std::cout << "Choose 0 or 1!!!!!\n";
                }
            }

            index = rand() % allCharactersFromTeam_t2.size();
            damageAmount = allCharactersFromTeam_t1[i]->dealDamage(combatIndex);

            if(damageAmount > 0){
                if(allCharactersFromTeam_t1[i]->getCharacterTypeName() == "Mix"){
                    if(rand() % 101 < 30){
                        allCharactersFromTeam_t1[i]->decreaseHp(damageAmount);
                        std::cout << "\033[33m" << allCharactersFromTeam_t1[i]->getName() << " DAMAGED HIM-/HERSELF!!!\033[0m\n";
                    }

                    if(allCharactersFromTeam_t1[i]->getHealthPoints() <= 0){
                        std::cout << "\033[33m" << allCharactersFromTeam_t1[i]->getName() << " Killed himself!!!\033[0m\n";

                        bool found = false;
                        for(const auto& name : alreadyLost){
                            if(name == allCharactersFromTeam_t1[i]->getName()){
                                found = true;
                                break;
                            }
                        }

                        if(!found){
                            for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                                if((*original)->getName() == allCharactersFromTeam_t1[i]->getName()){
                                    (*original)->increaseLosses();
                                    alreadyLost.push_back((*original)->getName());
                                    break;
                                }
                            }
                        }

                        allCharactersFromTeam_t1.erase(allCharactersFromTeam_t1.begin() + i);
                        --i;
                        continue;
                    }
                }
            }

            allCharactersFromTeam_t2[index]->decreaseHp(damageAmount);
            std::cout << allCharactersFromTeam_t1[i]->getName() << " deals " << damageAmount << " Damage to -> " << allCharactersFromTeam_t2[index]->getName() << "\n\n";

            for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); ){
                if((*c)->getHealthPoints() <= 0){
                    std::cout << "\n\033[33mFrom Team 1: " << (*c)->getName() << " DIED!!!\033[0m\n";

                    bool found = false;
                    for(const auto& name : alreadyLost){
                        if(name == (*c)->getName()){
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                        for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                            if((*original)->getName() == (*c)->getName()){
                                (*original)->increaseLosses();
                                alreadyLost.push_back((*original)->getName());
                                break;
                            }
                        }
                    }

                    c = allCharactersFromTeam_t2.erase(c);
                } else {
                    ++c;
                }
            }

            if(allCharactersFromTeam_t2.empty()){
                break;
            }
        }

        if(allCharactersFromTeam_t2.empty()){
            break;
        }

        printCharactersFromTeams(allCharactersFromTeam_t1, allCharactersFromTeam_t2);

        std::cout << "\n\nTeam2 make your move!\n";
        for(int i = 0; i < allCharactersFromTeam_t2.size(); i++){
            if(npc_2){
                combatIndex = rand() % 2;
                std::cout << allCharactersFromTeam_t2[i]->getName() << " Choose: " << combatIndex << " [NPC]\n";
            } else {
                while(true){
                    std::cout << allCharactersFromTeam_t2[i]->getName() << " Choose: ";

                    if(!(std::cin >> combatIndex)){
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid input!\n";
                        continue;
                    }

                    if(combatIndex >= 0 && combatIndex < 2){
                        break;
                    }

                    std::cout << "Choose 0 or 1!\n";
                }
            }

            index = rand() % allCharactersFromTeam_t1.size();
            damageAmount = allCharactersFromTeam_t2[i]->dealDamage(combatIndex);

            if(damageAmount > 0){
                if(allCharactersFromTeam_t2[i]->getCharacterTypeName() == "Mix"){
                    if(rand() % 101 < 30){
                        allCharactersFromTeam_t2[i]->decreaseHp(damageAmount);
                        std::cout << "\033[33m" << allCharactersFromTeam_t2[i]->getName() << " DAMAGED HIM-/HERSELF!!!\033[0m\n";
                    }

                    if(allCharactersFromTeam_t2[i]->getHealthPoints() <= 0){
                        std::cout << "\033[33m" << allCharactersFromTeam_t2[i]->getName() << " Killed himself!!!\033[0m\n";

                        bool found = false;
                        for(const auto& name : alreadyLost){
                            if(name == allCharactersFromTeam_t2[i]->getName()){
                                found = true;
                                break;
                            }
                        }

                        if(!found){
                            for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                                if((*original)->getName() == allCharactersFromTeam_t2[i]->getName()){
                                    (*original)->increaseLosses();
                                    alreadyLost.push_back((*original)->getName());
                                    break;
                                }
                            }
                        }

                        allCharactersFromTeam_t2.erase(allCharactersFromTeam_t2.begin() + i);
                        --i;
                        continue;
                    }
                }
            }

            allCharactersFromTeam_t1[index]->decreaseHp(damageAmount);
            std::cout << allCharactersFromTeam_t2[i]->getName() << " deals " << damageAmount << " Damage to -> " << allCharactersFromTeam_t1[index]->getName() << "\n\n";

            for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); ){
                if((*c)->getHealthPoints() <= 0){
                    std::cout << "\n\033[33mFrom Team 2: " << (*c)->getName() << " DIED!!!\033[0m\n";

                    bool found = false;
                    for(const auto& name : alreadyLost){
                        if(name == (*c)->getName()){
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                        for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                            if((*original)->getName() == (*c)->getName()){
                                (*original)->increaseLosses();
                                alreadyLost.push_back((*original)->getName());
                                break;
                            }
                        }
                    }

                    c = allCharactersFromTeam_t1.erase(c);
                } else {
                    ++c;
                }
            }

            if(allCharactersFromTeam_t1.empty()){
                break;
            }
        }

        if(allCharactersFromTeam_t1.empty()){
            break;
        }

        printCharactersFromTeams(allCharactersFromTeam_t1, allCharactersFromTeam_t2);
    }

    std::vector<std::string> alreadyWon;

    if(allCharactersFromTeam_t1.empty() && allCharactersFromTeam_t2.empty()){
        std::cout << "\n\n!!!IT IS A DRAW!!!\n\n";
    } else if(allCharactersFromTeam_t1.empty()){
        std::cout << "\n\n!!!TEAM 2 WINS!!!\n\n";

        for(auto c = allCharactersFromTeam_t2.begin(); c != allCharactersFromTeam_t2.end(); ++c){
            for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                if((*original)->getName() == (*c)->getName()){

                    bool found = false;
                    for(const auto& name : alreadyWon){
                        if(name == (*c)->getName()){
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                        (*original)->increaseWins();
                        alreadyWon.push_back((*c)->getName());
                    }

                    break;
                }
            }
        }
    } else if(allCharactersFromTeam_t2.empty()){
        std::cout << "\n\n!!!TEAM 1 WINS!!!\n\n";

        for(auto c = allCharactersFromTeam_t1.begin(); c != allCharactersFromTeam_t1.end(); ++c){
            for(auto original = allCharacters.begin(); original != allCharacters.end(); ++original){
                if((*original)->getName() == (*c)->getName()){

                    bool found = false;
                    for(const auto& name : alreadyWon){
                        if(name == (*c)->getName()){
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                        (*original)->increaseWins();
                        alreadyWon.push_back((*c)->getName());
                    }

                    break;
                }
            }
        }
    }
} //----------------------------------------------------------------//----------------------------------------------------------------//----------------------------------------------------------------//----------------------------------------------------------------

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


    startFight(team_1, team_2, false, false);




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
        startFight(team_1, team_2, false, false);
    }
}
void Game::Player_VS_NPC(std::string gameMode){
    std::string chosenCharacter = "";
    bool characterFound = false;
    Team team_1;
    Team team_2;

    printAllCharacters();

    if(gameMode == "1v1"){
        std::cout << "\nPlayer_1";
        while(characterFound == false){
            std::cout << "\nChoose Character (write name): ";
            std::cin >> chosenCharacter;

            for(auto c = allCharacters.begin(); c != allCharacters.end(); ++c){
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

        //NPC wählt random aus
        int randomIndex = rand() % allCharacters.size();
        team_2.addCharacterToTeam(*allCharacters[randomIndex]);

        startFight(team_1, team_2, false, true);
    }
    else if(gameMode == "3v3"){
        std::cout << "\nPlayer_1";
        for(int i = 0; i < 3; i++){
            characterFound = false;
            while(characterFound == false){
                std::cout << "\nChoose Character (write name): ";
                std::cin >> chosenCharacter;

                for(auto c = allCharacters.begin(); c != allCharacters.end(); ++c){
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

        std::cout << "\nNPC 2";
        for(int i = 0; i < 3; i++){
            int randomIndex = rand() % allCharacters.size();
            team_2.addCharacterToTeam(*allCharacters[randomIndex]);
        }

        startFight(team_1, team_2, false, true);
    }
}
void Game::NPC_VS_NPC(std::string gameMode){
    std::string chosenCharacter = "";
    bool characterFound = false;
    Team team_1;
    Team team_2;

    printAllCharacters();

    if(gameMode == "1v1"){
        //NPC_1 wählt random aus
        int randomIndex = rand() % allCharacters.size();
        team_1.addCharacterToTeam(*allCharacters[randomIndex]);

        //NPC_2 wählt random aus
        randomIndex = rand() % allCharacters.size();
        team_2.addCharacterToTeam(*allCharacters[randomIndex]);

        startFight(team_1, team_2, true, true);
    }
    else if(gameMode == "3v3"){
        //std::cout << "\nNPC 1";
        for(int i = 0; i < 3; i++){
            int randomIndex = rand() % allCharacters.size();
            team_1.addCharacterToTeam(*allCharacters[randomIndex]);
        }

        //std::cout << "\nNPC 2";
        for(int i = 0; i < 3; i++){
            int randomIndex = rand() % allCharacters.size();
            team_2.addCharacterToTeam(*allCharacters[randomIndex]);
        }

        startFight(team_1, team_2, true, true);
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
    while(true){
        std::cout << "Choose: ";
        if(!(std::cin >> createCharacterInput)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input!\n";
            continue;
        }

        if(createCharacterInput == 1 || createCharacterInput == 2){
            break;
        }

        std::cout << "Invalid choice!\n";
    }

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

        while(1){
            std::cout << "Hp: ";
            if(!(std::cin >> healthPoints)){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input!\n";
                continue;
            }

            if(healthPoints > 0){
                break;
            }

            std::cout << "Hp needs to be bigger then 0!!!\n";
        }

            std::cout << "\nChoose Character Type\n";

            std::cout << "\n(1) Risky"
                      << "\n    + +40% hit damage"
                      << "\n    + -50% hit chance\n";

            std::cout << "\n(2) Mix"
                      << "\n    + +10% hit damage"
                      << "\n    + +20% hit chance"
                      << "\n    - 30% chance to take self-damage\n";

            std::cout << "\n(3) NoRisky"
                      << "\n    - -10% hit damage\n";

            std::cout << "\nChoose: "; std::cin >> createCharacterInput;



        if(createCharacterInput == 1){
            addCharacterToGame(std::make_unique<RiskyCharacter>(name, healthPoints));
        }
        else if(createCharacterInput == 2){
            addCharacterToGame(std::make_unique<MixCharacter>(name, healthPoints));
        }
        else if(createCharacterInput == 3){
            addCharacterToGame(std::make_unique<NoRiskyCharacter>(name, healthPoints));
        } else {
            std::cout << "WRONG INPUT!";
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
              << "\n    + -50% hit chance\n";

    std::cout << "\n(2) Mix"
              << "\n    + +10% hit damage"
              << "\n    + +20% hit chance"
              << "\n    - 30% chance to take self-damage \n";

    std::cout << "\n(3) NoRisky"
              << "\n    - -10% hit damage\n";

    std::cout << "\nAll Entscheidungsbaeume: \n\n";
    printEntscheidungsbaeume();
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

void Game::printCharactersFromTeams(std::vector<std::unique_ptr<Character>>& allCharactersFromTeam_t1,
                                    std::vector<std::unique_ptr<Character>>& allCharactersFromTeam_t2){
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
}

void Game::printAllAbilitys(){
    int i = 0;
    for(auto a = allAbilitys.begin(); a != allAbilitys.end(); a++){
        std::cout << "- "
        <<"("<<i<<")"
        << "Name: " << (*a)->getName()
        << ", Damage: " << (*a)->getDamage()
        << ", Hit-Chance: " << (*a)->getHitChance() <<"%"<< std::endl;
        i++;
    }
}




void Game::addEntscheidungsbaumToGame(std::unique_ptr<Entscheidungsbaum> newEntscheidungsbaum){
    allEntscheidungsbaum.push_back(std::move(newEntscheidungsbaum));
}


void Game::printEntscheidungsbaeume(){
    int i = 0;
    for(auto a = allEntscheidungsbaum.begin(); a != allEntscheidungsbaum.end(); a++){
        std::cout << "- "
        <<"("<<i<<")"
        << "Name: " << (*a)->getName() << " Description: " << (*a)->getDescription() << "\n\n";
        i++;
    }
}

