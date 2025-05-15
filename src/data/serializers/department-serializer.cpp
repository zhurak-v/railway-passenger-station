#include "entities/department.hpp"
#include <iomanip>

std::string Department::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << std::quoted(getDepartmentName());
    return oss.str();
}

std::shared_ptr<Department> Department::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    iss >> id;

    std::string department_name;
    iss >> std::quoted(department_name);

    return std::make_shared<Department>(id, department_name);
}
