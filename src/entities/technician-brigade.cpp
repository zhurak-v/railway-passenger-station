#include "entities/technician-brigade.hpp"

TechnicianBrigade::TechnicianBrigade(
    const std::string& id,
    const std::string& brigade_name,
    const std::string& specialization
) : Brigade(id, brigade_name, specialization) {}

std::string TechnicianBrigade::staticClass()
{
    return "TechnicianBrigade";
}
std::string TechnicianBrigade::getClass() const { 
    return staticClass();
}