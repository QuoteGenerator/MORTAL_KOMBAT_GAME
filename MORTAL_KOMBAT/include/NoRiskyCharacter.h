#ifndef NORISKYCHARACTER_H
#define NORISKYCHARACTER_H

#include "Character.h"


class NoRiskyCharacter : public Character
{
    public:
        NoRiskyCharacter(std::string name, int hp);
        std::string getCharacterTypeName() const override;

    protected:

    private:
};

#endif // NORISKYCHARACTER_H
