#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Ability.h"
#include <vector>
#include <memory>

class Game
{
    public:
        Game();
        void printGameMenu();
        void printGameModes(); //1v1 or 3v3 => Player vs Player, NPC vs NPC, Player vs NPC
        void printCharacterCreation(); //character hinzufügen oder löschen
        void printCharacters(); //Alle Character und Statistik anzeigen und Abilitys
        void quit(); //Spiel beenden;

        void addCharacterToGame(std::unique_ptr<Character> newCharacter);
        void addAbilityToGame(std::unique_ptr<Ability> newAbility);


    private:
        std::vector<std::unique_ptr<Character>> allCharacters;
        std::vector<std::unique_ptr<Ability>> allAblilitys;
};

#endif // GAME_H
