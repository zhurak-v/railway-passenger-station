#include "entities/head-department.hpp"
#include <iomanip>

std::string HeadDepartment::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << std::quoted(getFullName()) << " "
        << static_cast<int>(getSex()) << " "
        << getBrithDate().serialize() << " "
        << getStartWork().serialize() << " "
        << getChildrenCount() << " "
        << getSalary();

    return oss.str();
}

std::shared_ptr<HeadDepartment> HeadDepartment::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id, full_name;
    int sex;
    std::string birth, start_work;
    int children_count;
    double salary;

    iss >> id >> std::quoted(full_name) >> sex >> birth >> start_work >> children_count >> salary;

    return std::make_shared<HeadDepartment>(id, full_name, static_cast<SEX>(sex), Date::deserialize(birth), Date::deserialize(start_work), children_count, salary);
}
