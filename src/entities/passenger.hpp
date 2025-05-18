#pragma once
#include <sstream>
#include <vector>
#include "entities/base.hpp"

class Passenger : public Base
{
private:
    bool has_baggage;

public:
    Passenger(
        const std::string& id,
        const bool has_baggage
    );
    ~Passenger() = default;

public:
    bool getHasBaggage() const;
    
public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Passenger> deserialize(const std::string &data);
};
