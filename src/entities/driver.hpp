#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "entities/base-employee.hpp"
#include "common/date/date.hpp"

class Driver : public Employee
{
private:
    std::vector<Date> passed_medexam;

public:
    Driver(
        const std::string &id,
        const std::string &full_name,
        SEX sex,
        Date &birth,
        Date &start_work,
        int children_count,
        double salary,
        std::vector<Date> &passed_medexam);

    ~Driver() = default;

public:
    std::vector<Date> getPassedMedexam() const;
    void setPassedMedexam(Date date);

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<Driver> deserialize(const std::string &data);
};