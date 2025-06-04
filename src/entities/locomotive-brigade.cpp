#include "entities/locomotive-brigade.hpp"

LocomotiveBrigade::LocomotiveBrigade(
    const std::string& id,
    const std::string& brigade_name
) : Brigade(id, brigade_name) {}

std::string LocomotiveBrigade::staticClass()
{
    return "LocomotiveBrigade";
}
std::string LocomotiveBrigade::getClass() const { 
    return staticClass();
}