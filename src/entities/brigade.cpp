#include "entities/brigade.hpp"

Brigade::Brigade(
    const std::string &id,
    const std::string &brigade_name) : Base(id),
                                        brigade_name(brigade_name) {};

   
std::string Brigade::getBrigadeName() const
{
    return brigade_name;
}

double Brigade::getAvarageSalary() const
{
    return average_salary;
}

void Brigade::setAverageSalary(const std::vector<double> &salaries)
{
    double sum = 0;
    for (const double salary : salaries)
    {
        sum += salary;
    }
    average_salary = sum / salaries.size();
}

std::string Brigade::staticClass() {
    return "Brigade";
}

std::string Brigade::getClass() const { 
    return staticClass();
}