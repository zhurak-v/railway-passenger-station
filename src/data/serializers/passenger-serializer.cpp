#include "entities/passenger.hpp"
#include <iomanip>

std::string Passenger::serialize() const
{
    std::ostringstream oss;
    oss << 
    getId() << " " << 
    getHasBaggage();
    
    return oss.str();
}

std::shared_ptr<Passenger> Passenger::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    bool has_baggage;

    iss >> id >> has_baggage;

    return std::make_shared<Passenger>(id, has_baggage);
}
