#ifndef ABILITY_H
#define ABILITY_H
#include <string>

class Ability
{
    public:
        Ability(std::string name, int damage, float hitChance);

        std::string getName();
        int getDamage();
        float getHitChance();

    private:
        std::string name;
        int damage;
        float hitChance;
};

#endif // ABILITY_H
