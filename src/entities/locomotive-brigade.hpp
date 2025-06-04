#pragma once
#include "entities/brigade.hpp"

class LocomotiveBrigade : public Brigade
{
public:
    LocomotiveBrigade(
        const std::string& id,
        const std::string& brigade_name
    );
    ~LocomotiveBrigade() = default;
 
public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const;
    static std::shared_ptr<LocomotiveBrigade> deserialize(const std::string &data);
};
