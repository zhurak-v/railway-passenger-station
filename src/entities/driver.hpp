#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "entities/base-employee.hpp"

class Driver : public Employee
{
private:
    std::vector<int> passed_medexam;

public:
    Driver(
        const std::string& id,
        const std::string &full_name,
        bool sex,
        int age,
        int work_experience,
        int children_count,
        float salary,
        std::vector<int>& passed_medexam
    );

    ~Driver() = default;

public:
    std::vector<int> getPassedMedexam() const;
    void setPassedMedexam(int year);

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<Driver> deserialize(const std::string& data);
};