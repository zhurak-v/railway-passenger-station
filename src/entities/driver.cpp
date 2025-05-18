#include "entities/driver.hpp"

Driver::Driver(
    const std::string &id,
    const std::string &full_name,
    SEX sex,
    Date &birth,
    Date &start_work,
    int children_count,
    double salary,
    std::vector<Date>& passed_medexam
    )
    : Employee(id, full_name, sex, birth, start_work, children_count, salary),
    passed_medexam(passed_medexam) {};

std::string Driver::staticClass()
{
    return "Driver";
}
std::string Driver::getClass() const { 
    return staticClass();
}

std::vector<Date> Driver::getPassedMedexam() const {
    return passed_medexam;
}

void Driver::setPassedMedexam(Date date) {
    passed_medexam.push_back(date);
}