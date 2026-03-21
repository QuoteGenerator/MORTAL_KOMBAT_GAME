#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include "Character.h"

class Team
{
    public:
        Team();
        //void addCharacterToTeam(Character newCharacter);


    private:
        std::vector<Character> allCharactersInThisTeam;
};

#endif // TEAM_H
