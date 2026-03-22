#ifndef NORISKYCHARACTER_H
#define NORISKYCHARACTER_H

#include "Character.h"

class NoRiskyCharacter : public Character
{
    public:
        NoRiskyCharacter(std::string name, int hp);
        std::string getCharacterTypeName() const override;
        std::unique_ptr<Character> clone() override;
        int dealDamage(int index) override;

    protected:

    private:
};

#endif // NORISKYCHARACTER_H
