#include "entities/dispatcher.hpp"

std::string Dispatcher::staticClass()
{
    return "Dispatcher";
}
std::string Dispatcher::getClass() const { 
    return staticClass();
}