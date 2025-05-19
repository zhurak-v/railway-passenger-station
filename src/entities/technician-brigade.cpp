#include "entities/technician-brigade.hpp"

TechnicianBrigade::TechnicianBrigade(
    const std::string& id,
    const std::string& brigade_name
) : Brigade(id, brigade_name) {}

std::string TechnicianBrigade::staticClass()
{
    return "TechnicianBrigade";
}
std::string TechnicianBrigade::getClass() const { 
    return staticClass();
}