#include "entities/driver.hpp"
#include <iomanip>

std::string Driver::serialize() const {
    std::ostringstream oss;
    oss << getId() << " "
        << std::quoted(getFullName()) << " "
        << getSex() << " "
        << getAge() << " "
        << getWorkExperience() << " "
        << getChildrenCount() << " "
        << getSalary();

    for (int year : passed_medexam) {
        oss << " " << year;
    }

    return oss.str();
}

std::shared_ptr<Driver> Driver::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string id, full_name;
    bool sex;
    int age, work_experience, children_count;
    float salary;

    iss >> id >> std::quoted(full_name) >> sex >> age >> work_experience >> children_count >> salary;

    std::vector<int> passed_medexam;
    int year;
    while (iss >> year) {
        passed_medexam.push_back(year);
    }

    return std::make_shared<Driver>(id, full_name, sex, age, work_experience, children_count, salary, passed_medexam);
}