#ifndef ABILITY_H
#define ABILITY_H
#include <string>
#include <memory>

class Ability
{
    public:
        Ability(std::string name, int damage, float hitChance);

        std::string getName();
        int getDamage();
        float getHitChance();

        std::unique_ptr<Ability> clone();

    private:
        std::string name;
        int damage;
        float hitChance;
};

#endif // ABILITY_H
