#include "entities/locomotive.hpp"

Locomotive::Locomotive(
    const std::string &id,
    const Date &manufacture_date,
    std::vector<Date>& passed_tech_inspection,
    std::vector<Date>& repairs,
    int completed_routes,
    int completed_routes_before_repair

) : Base(id), 
    manufacture_date(manufacture_date), 
    passed_tech_inspection(passed_tech_inspection), 
    repairs(repairs), 
    completed_routes(completed_routes),
    completed_routes_before_repair(completed_routes_before_repair) {}

std::vector<Date> Locomotive::getPassedTechInspection() const {
    return passed_tech_inspection;
}

std::vector<Date> Locomotive::getRepairs() const {
    return repairs;
}

int Locomotive::getRepairsCount() const {
    return getRepairs().size();
}

int Locomotive::getCompletedRoutes() const {
    return completed_routes;
}

int Locomotive::getCompletedRoutesBeforeRepair() const {
    return completed_routes_before_repair;
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