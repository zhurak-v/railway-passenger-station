#pragma once

#include <iostream>
#include <string>
#include "entities/base-employee.hpp"

class Technician : public Employee
{
public:
    using Employee::Employee;
    ~Technician() = default;

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<Technician> deserialize(const std::string& data);
};