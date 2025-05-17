#pragma once
#include <vector>
#include <sstream> 
#include <string> 
#include "entities/base.hpp"

class Brigade : public Base
{
private:
    std::string brigade_name;
    std::string specialization;
    double avarage_alary = 0;

public:
    Brigade(
        const std::string& id,
        const std::string& brigade_name,
        const std::string& specialization
    );
    virtual ~Brigade() = default;

public:
    std::string getBrigadeName() const;
    std::string getSpecialization() const;
    double getAvarageSalary() const;
    void setAvarageSalary(const std::vector<double>& salaries);
    
public:
    std::string getClass() const override;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Brigade> deserialize(const std::string &data);
};
