#pragma once

#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "common/date/date.hpp"
#include "entities/base.hpp"

class Locomotive : public Base
{
private:
    std::vector<Date> passed_tech_inspection;
    std::vector<Date> repairs;
    Date manufacture_date;
    int completed_routes;
    int completed_routes_before_repair;

public:
    Locomotive(
        const std::string &id,
        const Date& manufacture_date,
        std::vector<Date>& passed_tech_inspection,
        std::vector<Date>& repairs,
        int completed_routes,
        int completed_routes_before_repair
    );                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    ~Locomotive() = default;

public:
    std::vector<Date> getPassedTechInspection() const;
    std::vector<Date> getRepairs() const;

    int getRepairsCount() const;
    Date getManufactureDate() const;

    int getCompletedRoutes() const;
    int getCompletedRoutesBeforeRepair() const;

public: 
    std::string getClass() const final;   
    static std::string staticClass();

public:
    std::string serialize() const final;
    static std::shared_ptr<Locomotive> deserialize(const std::string &data);
};
