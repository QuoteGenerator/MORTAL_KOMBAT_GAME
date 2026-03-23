#ifndef ENTSCHEIDUNGSBAUM_H
#define ENTSCHEIDUNGSBAUM_H

#include <string>


class Entscheidungsbaum
{
    public:
        Entscheidungsbaum(std::string newName, std::string newDescription);
        std::string getName();
        std::string getDescription();


    protected:

    private:
        std::string name;
        std::string description;

};

#endif // ENTSCHEIDUNGSBAUM_H
