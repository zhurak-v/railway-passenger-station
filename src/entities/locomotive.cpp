#include "entities/locomotive.hpp"

Locomotive::Locomotive(
    const std::string &id,
    const Date &manufacture_year) : Base(id), manufacture_date(manufacture_date) {}

std::vector<Date> Locomotive::getPassedTechInspection() const {
    return passed_tech_inspection;
}

void Locomotive::setPassedTechInspection(Date date) {
    passed_tech_inspection.push_back(date);
}

std::vector<Date> Locomotive::getRepairs() const {
    return repairs;
}

int Locomotive::getRepairsCount() const {
    return getRepairs().size();
}

void Locomotive::setRepairs(Date date) {
    repairs.push_back(date);
}

Date Locomotive::getManufactureDate() const {
    return manufacture_date;
}

std::string Locomotive::staticClass() {
    return "Locomotive";
}

std::string Locomotive::getClass() const { 
    return staticClass();
}