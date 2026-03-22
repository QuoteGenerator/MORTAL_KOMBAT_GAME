#ifndef RISKYCHARACTER_H
#define RISKYCHARACTER_H

#include "Character.h"


class RiskyCharacter : public Character
{
    public:
        RiskyCharacter(std::string name, int hp);
        std::string getCharacterTypeName() const override;
        std::unique_ptr<Character> clone() override;
        int dealDamage(int index) override;

    protected:

    private:
};

#endif // RISKYCHARACTER_H
