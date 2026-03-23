#include "Entscheidungsbaum.h"

Entscheidungsbaum::Entscheidungsbaum(std::string newName, std::string newDescription)
{
    name = newName;
    description = newDescription;
}

std::string Entscheidungsbaum::getName(){
    return name;
}

std::string Entscheidungsbaum::getDescription(){
    return description;
}
