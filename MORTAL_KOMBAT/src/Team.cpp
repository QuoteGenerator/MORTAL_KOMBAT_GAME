#include "Team.h"
#include "Character.h"

Team::Team()
{
    //ctor
}


void Team::addCharacterToTeam(Character& newCharacter){
    allCharactersFromThisTeam.push_back(newCharacter.clone());
}


std::vector<std::unique_ptr<Character>>& Team::getAllCharactersFromThisTeam(){
    return allCharactersFromThisTeam;
}
