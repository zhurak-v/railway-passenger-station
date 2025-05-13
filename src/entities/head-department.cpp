#include "entities/head-department.hpp"

HeadDepartment::HeadDepartment(
    const std::string &id,
    const std::string &full_name,
    bool sex,
    int age,
    int work_experience,
    int children_count,
    float salary)
    : Employee(id, full_name, sex, age, work_experience, children_count, salary) {};

std::string HeadDepartment::staticClass()
{
    return "HeadDepartment";
}
std::string HeadDepartment::getClass() const { 
    return staticClass();
}