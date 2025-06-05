#include "entities/passenger.hpp"

Passenger::Passenger(
    const std::string& id,
    const bool has_baggage,
    SEX sex,
    Date& birth
) : Base(id), has_baggage(has_baggage), sex(sex), birth(birth)  {}

bool Passenger::getHasBaggage() const {
    return has_baggage;
}
SEX Passenger::getSex() const
{
  return sex;
};

Date Passenger::getBrithDate() const
{
  return birth;
};

std::string Passenger::staticClass() {
    return "Passenger";
}

std::string Passenger::getClass() const { 
    return staticClass();
}