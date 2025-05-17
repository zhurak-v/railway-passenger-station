#include "entities/technician.hpp"

Technician::Technician(
    const std::string &id,
    const std::string &full_name,
    bool sex,
    int age,
    int work_experience,
    int children_count,
    double salary)
    : Employee(id, full_name, sex, age, work_experience, children_count, salary) {};

std::string Technician::staticClass()
{
    return "Technician";
}
std::string Technician::getClass() const { 
    return staticClass();
}