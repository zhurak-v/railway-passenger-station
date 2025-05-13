#include "entities/department.hpp"

Department::Department(
    const std::string &id,
    const std::string &department_name) : Base(id), department_name(department_name) {}

std::string Department::getDepartmentName() const
{
    return department_name;
};

std::string Department::staticClass() {
    return "Department";
};

std::string Department::getClass() const
{
   return staticClass();
};