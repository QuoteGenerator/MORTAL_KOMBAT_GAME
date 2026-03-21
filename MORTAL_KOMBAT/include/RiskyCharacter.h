#ifndef RISKYCHARACTER_H
#define RISKYCHARACTER_H

#include "Character.h"


class RiskyCharacter : public Character
{
    public:
        RiskyCharacter(std::string name, int hp);
        std::string getCharacterTypeName() const override;

    protected:

    private:
};

#endif // RISKYCHARACTER_H
