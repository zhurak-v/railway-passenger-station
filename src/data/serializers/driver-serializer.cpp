#include "entities/driver.hpp"


std::string Driver::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << getFullName() << " "
        << getSex() << " "
        << getAge() << " "
        << getWorkExperience() << " "
        << getChildrenCount() << " "
        << getSalary();

    for (const auto& [year, passed] : getPassedMedexam()) {
        oss << " " << year << ":" << (passed ? "1" : "0");
    }

    return oss.str();
}


std::shared_ptr<Driver> Driver::deserialize(const std::string& data)
{
    std::istringstream iss(data);
    std::string id, full_name;
    bool sex;
    int age, work_experience, children_count;
    float salary;

    iss >> id >> full_name >> sex >> age >> work_experience >> children_count >> salary;

    std::map<int, bool> passed_medexam;
    std::string token;
    while (iss >> token) {
        auto pos = token.find(':');
        if (pos != std::string::npos) {
            int year = std::stoi(token.substr(0, pos));
            bool passed = token.substr(pos + 1) == "1";
            passed_medexam[year] = passed;
        }
    }

    return std::make_shared<Driver>(id, full_name, sex, age, work_experience, children_count, salary, passed_medexam);
}