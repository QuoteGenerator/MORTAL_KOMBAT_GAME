#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <memory>
#include "Character.h"

class Team
{
    public:
        Team();
        void addCharacterToTeam(Character& newCharacter);
        std::vector<std::unique_ptr<Character>>& getAllCharactersFromThisTeam();


    private:
        std::vector<std::unique_ptr<Character>> allCharactersFromThisTeam;
};

#endif // TEAM_H
