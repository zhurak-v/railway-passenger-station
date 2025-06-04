#include "entities/brigade.hpp"

Brigade::Brigade(
    const std::string &id,
    const std::string &brigade_name) : Base(id),
                                        brigade_name(brigade_name) {};

   
std::string Brigade::getBrigadeName() const
{
    return brigade_name;
}

std::string Brigade::staticClass() {
    return "Brigade";
}

std::string Brigade::getClass() const { 
    return staticClass();
}