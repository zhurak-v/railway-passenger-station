#pragma once

#include <iostream>
#include <string>
#include "entities/base-employee.hpp"

class Cashier : public Employee
{
public:
    using Employee::Employee;

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<Cashier> deserialize(const std::string& data);
};