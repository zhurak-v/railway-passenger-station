#include "entities/department.hpp"

std::string Department::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << getDepartmentName();
    return oss.str();
}

std::shared_ptr<Department> Department::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    std::string department_name;
    iss >> id >> department_name;
    return std::make_shared<Department>(id, department_name);
}