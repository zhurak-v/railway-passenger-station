#include "entities/locomotive-staff.hpp"

std::string Staff::staticClass()
{
    return "Staff";
}
std::string Staff::getClass() const { 
    return staticClass();
}