#ifndef HEALENTSCHEIDUNGSBAUM_H
#define HEALENTSCHEIDUNGSBAUM_H

#include "Entscheidungsbaum.h"


class HealEntscheidungsbaum : public Entscheidungsbaum
{
    public:
        HealEntscheidungsbaum(std::string newName, std::string description);
        std::unique_ptr<Entscheidungsbaum> clone() override;
        void afterAttack(Character& myself, std::vector<std::unique_ptr<Character>>& enemyTeam) override;
};

#endif // HEALENTSCHEIDUNGSBAUM_H
