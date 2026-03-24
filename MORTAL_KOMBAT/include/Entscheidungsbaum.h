#ifndef ENTSCHEIDUNGSBAUM_H
#define ENTSCHEIDUNGSBAUM_H

#include <string>
#include <memory>
#include <vector>

#include "Character.h"

class Character;


class Entscheidungsbaum
{
    public:
        Entscheidungsbaum(std::string newName, std::string newDescription);
        std::string getName();
        std::string getDescription();

        virtual std::unique_ptr<Entscheidungsbaum> clone() = 0;
        virtual void afterAttack(Character& myself, std::vector<std::unique_ptr<Character>>& enemyTeam) = 0;
        //get Entscheidungsbaum name mit virual und = 0


    protected:

    private:
        std::string name;
        std::string description;

};

#endif // ENTSCHEIDUNGSBAUM_H
