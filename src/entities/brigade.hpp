#pragma once
#include <vector>
#include <sstream> 
#include <string> 
#include "entities/base.hpp"

class Brigade : public Base
{
private:
    std::string brigade_name;
    double average_salary = 0;

public:
    Brigade(
        const std::string& id,
        const std::string& brigade_name
    );
    virtual ~Brigade() = default;

public:
    std::string getBrigadeName() const;
    double getAvarageSalary() const;
    void setAverageSalary(const std::vector<double>& salaries);
    
public:
    std::string getClass() const override;
    static std::string staticClass();
};
