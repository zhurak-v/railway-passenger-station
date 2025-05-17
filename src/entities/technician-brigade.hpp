#pragma once
#include "entities/brigade.hpp"

class TechnicianBrigade : public Brigade
{
public:
    TechnicianBrigade(
        const std::string& id,
        const std::string& brigade_name,
        const std::string& specialization
    );
    ~TechnicianBrigade() = default;
 
public:
    std::string getClass() const final;
    static std::string staticClass();
};
