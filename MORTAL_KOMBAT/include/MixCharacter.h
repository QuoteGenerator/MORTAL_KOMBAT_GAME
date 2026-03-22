#ifndef MIXCHARACTER_H
#define MIXCHARACTER_H

#include "Character.h"


class MixCharacter : public Character
{
    public:
        MixCharacter(std::string name, int hp);
        std::string getCharacterTypeName() const override;
        std::unique_ptr<Character> clone() override;
        int dealDamage(int index) override;

    protected:

    private:
};

#endif // MIXCHARACTER_H
