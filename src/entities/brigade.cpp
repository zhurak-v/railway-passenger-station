#include "entities/brigade.hpp"

Brigade::Brigade(
    const std::string &id,
    const std::string &brigade_name,
    const std::string& specialization) : Base(id),
                                        brigade_name(brigade_name), specialization(specialization) {};

   
std::string Brigade::getBrigadeName() const
{
    return brigade_name;
}

std::string Brigade::getSpecialization() const
{
    return specialization;
}

double Brigade::getAvarageSalary() const
{
    return avarage_alary;
}

void Brigade::setAvarageSalary(const std::vector<double> &salaries)
{
    double sum = 0;
    for (const double salary : salaries)
    {
        sum += salary;
    }
    avarage_alary = sum / salaries.size();
}

std::string Brigade::staticClass() {
    return "Brigade";
}

std::string Brigade::getClass() const { 
    return staticClass();
}