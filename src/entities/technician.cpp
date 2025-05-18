#include "entities/technician.hpp"

std::string Technician::staticClass()
{
    return "Technician";
}
std::string Technician::getClass() const { 
    return staticClass();
}