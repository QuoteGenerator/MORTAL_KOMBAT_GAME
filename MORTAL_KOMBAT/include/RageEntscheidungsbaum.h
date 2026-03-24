#ifndef RAGEENTSCHEIDUNGSBAUM_H
#define RAGEENTSCHEIDUNGSBAUM_H

#include "Entscheidungsbaum.h"


class RageEntscheidungsbaum : public Entscheidungsbaum
{
    public:
        RageEntscheidungsbaum(std::string newName, std::string description);
        std::unique_ptr<Entscheidungsbaum> clone() override;
        void afterAttack(Character& myself, std::vector<std::unique_ptr<Character>>& enemyTeam) override;
};

#endif // RAGEENTSCHEIDUNGSBAUM_H
