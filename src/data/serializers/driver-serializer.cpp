#include "entities/driver.hpp"
#include <iomanip>

std::string Driver::serialize() const {
    std::ostringstream oss;
    oss << getId() << " "
        << std::quoted(getFullName()) << " "
        << static_cast<int>(getSex()) << " "
        << getBrithDate().serialize() << " "
        << getStartWork().serialize() << " "
        << getChildrenCount() << " "
        << getSalary();

    const auto passed_medexam = getPassedMedexam();
    for (Date date : passed_medexam) {
        oss << " " << date.serialize();
    }

    return oss.str();
}

std::shared_ptr<Driver> Driver::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string id, full_name;
    int sex;
    std::string birth, start_work;
    int children_count;
    double salary;

    iss >> id >> std::quoted(full_name) >> sex >> birth >> start_work >> children_count >> salary;

    std::vector<Date> passed_medexam;
    
    std::string date_str;
    while (iss >> date_str) {
        passed_medexam.push_back(Date::deserialize(date_str));
    }

    return std::make_shared<Driver>(id, full_name, static_cast<SEX>(sex), Date::deserialize(birth), Date::deserialize(start_work), children_count, salary, passed_medexam);
}