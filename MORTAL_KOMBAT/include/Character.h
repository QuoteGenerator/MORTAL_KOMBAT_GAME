#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>


class Character
{
    public:
        Character(std::string name, int healthPoints);
        virtual ~Character();
        std::string getName();
        int getHealthPoints();

    protected:

    private:
        std::string name;
        int healthPoints;
        int lostGames = 0;
        int wonGames = 0;
};

#endif // CHARACTER_H
