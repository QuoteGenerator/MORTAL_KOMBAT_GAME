#ifndef MIXCHARACTER_H
#define MIXCHARACTER_H

#include "Character.h"


class MixCharacter : public Character
{
    public:
        MixCharacter(std::string name, int hp);
        std::string getCharacterTypeName() const override;

    protected:

    private:
};

#endif // MIXCHARACTER_H
