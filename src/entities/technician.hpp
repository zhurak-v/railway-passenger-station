#pragma once

#include <iostream>
#include <string>
#include "entities/base-employee.hpp"

class Technician : public Employee
{
public:
    Technician(
        const std::string& id,
        const std::string &full_name,
        bool sex,
        int age,
        int work_experience,
        int children_count,
        double salary);

    ~Technician() = default;

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<Technician> deserialize(const std::string& data);
};