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

std::string HeadDepartment::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << getFullName() << " " << getSex() << " " << getAge() << " "
        << getWorkExperience() << " " << getChildrenCount() << " " << getSalary();
    return oss.str();
}

std::shared_ptr<HeadDepartment> HeadDepartment::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    std::string full_name;
    bool sex;
    int age, work_experience, children_count;
    float salary;

    iss >> id >> full_name >> sex >> age >> work_experience >> children_count >> salary;

    return std::make_shared<HeadDepartment>(id, full_name, sex, age, work_experience, children_count, salary);
}