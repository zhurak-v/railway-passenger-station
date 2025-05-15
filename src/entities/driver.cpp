#include "entities/driver.hpp"

Driver::Driver(
    const std::string &id,
    const std::string &full_name,
    bool sex,
    int age,
    int work_experience,
    int children_count,
    float salary,
    std::vector<int>& passed_medexam
    )
    : Employee(id, full_name, sex, age, work_experience, children_count, salary),
    passed_medexam(passed_medexam) {};

std::string Driver::staticClass()
{
    return "Driver";
}
std::string Driver::getClass() const { 
    return staticClass();
}

std::vector<int> Driver::getPassedMedexam() const {
    return passed_medexam;
}

void Driver::setPassedMedexam(int year) {
    passed_medexam.push_back(year);
}