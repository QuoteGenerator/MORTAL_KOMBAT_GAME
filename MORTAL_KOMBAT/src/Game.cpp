#include "Game.h"
#include <iostream>
#include <vector>
#include <memory>

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
    std::cout << "(1) 1v1" << std::endl;
    std::cout << "(2) Team vs Team" << std::endl;
    std::cout << "(3) Game Menu" << std::endl;
    std::cout << "Choose: "; std::cin >> gameModeInput;

    if(gameModeInput == 3){
        return;
    } else if(gameModeInput == 1){
        gameModeInput = 0;
    } else if(gameModeInput == 2){
        gameModeInput = 0;
    }

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
        std::cout << "\nHp: "; std::cin >> healthPoints;

        auto newCharacter = std::make_unique<Character>(name, healthPoints);

        allCharacters.push_back(move(newCharacter));
    }

}

void Game::printCharacters(){
    std::cout << "\nAll Characters: " << std::endl;
    for(auto c = allCharacters.begin(); c != allCharacters.end(); c++){
        std::cout << "- " << "Name: " << (*c)->getName()  << ", Hp: " << (*c)->getHealthPoints()<< std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nAll Abilitys: " << std::endl;
    for(auto a = allAblilitys.begin(); a != allAblilitys.end(); a++){


        std::cout << "- "
        << "Name: " << (*a)->getName()
        << ", Damage: " << (*a)->getDamage()
        << ", Hit-Chance: " << (*a)->getHitChance() <<"%"<< std::endl;
    }

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
