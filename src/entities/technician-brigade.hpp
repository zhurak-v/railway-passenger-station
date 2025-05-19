#pragma once
#include "entities/brigade.hpp"

class TechnicianBrigade : public Brigade
{
public:
    TechnicianBrigade(
        const std::string& id,
        const std::string& brigade_name
    );
    ~TechnicianBrigade() = default;
 
public:
    std::string getClass() const final;
    static std::string staticClass();
};
