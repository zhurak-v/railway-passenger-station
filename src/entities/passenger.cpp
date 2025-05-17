#include "entities/passenger.hpp"

Passenger::Passenger(
    const std::string& id,
    const bool has_baggage
) : Base(id), has_baggage(has_baggage) {}

bool Passenger::getHasBaggage() const {
    return has_baggage;
}

std::string Passenger::staticClass() {
    return "Passenger";
}

std::string Passenger::getClass() const { 
    return staticClass();
}