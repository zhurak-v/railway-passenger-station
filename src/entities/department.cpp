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