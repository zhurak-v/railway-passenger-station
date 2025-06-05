#include "entities/passenger.hpp"
#include <iomanip>

std::string Passenger::serialize() const
{
    std::ostringstream oss;
    oss << 
    getId() << " "
    << getHasBaggage() << " "
    << static_cast<int>(getSex()) << " "
    << getBrithDate().serialize();;
    
    return oss.str();
}

std::shared_ptr<Passenger> Passenger::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    bool has_baggage;
    int sex;
    std::string birth;

    iss >> id >> has_baggage >> sex >> birth;

    return std::make_shared<Passenger>(id, has_baggage, static_cast<SEX>(sex), Date::deserialize(birth));
}
