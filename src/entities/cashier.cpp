#include "entities/cashier.hpp"

std::string Cashier::staticClass()
{
    return "Cashier";
}
std::string Cashier::getClass() const { 
    return staticClass();
}