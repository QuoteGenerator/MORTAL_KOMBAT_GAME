#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <memory>
#include <array>
#include "Ability.h"
#include "Entscheidungsbaum.h"

class Character
{
    public:
        Character(std::string name, int healthPoints);
        virtual ~Character();
        std::string getName();
        int getHealthPoints();
        int getLostGames();
        int getWonGames();

        virtual std::string getCharacterTypeName() const = 0;
        virtual std::unique_ptr<Character> clone() = 0;
        virtual int dealDamage(int index) = 0;

        std::array<std::unique_ptr<Ability>, 2>& getCharacterAbilitys();
        void addCharacterAbility(Ability& newAbility, int index);
        void decreaseHp(int dealedDamage);

        void increaseLosses();
        void increaseWins();

        void setEntscheidungsbaum(std::unique_ptr<Entscheidungsbaum> newBaum);
        Entscheidungsbaum* getEntscheidungsbaum();



    protected:

    private:
        std::array<std::unique_ptr<Ability>, 2> abilitys;
        std::array<std::unique_ptr<Entscheidungsbaum>, 1> meinEntscheidungsbaum;
        std::string name;
        int healthPoints;
        int lostGames = 0;
        int wonGames = 0;

};

#endif // CHARACTER_H
