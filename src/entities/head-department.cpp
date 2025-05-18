#include "entities/head-department.hpp"

std::string HeadDepartment::staticClass()
{
    return "HeadDepartment";
}
std::string HeadDepartment::getClass() const { 
    return staticClass();
}