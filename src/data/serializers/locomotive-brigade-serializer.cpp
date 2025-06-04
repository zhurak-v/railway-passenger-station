#include "entities/locomotive-brigade.hpp"
#include <iomanip>

std::string LocomotiveBrigade::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << 
    std::quoted(getBrigadeName());

    return oss.str();
}

std::shared_ptr<LocomotiveBrigade> LocomotiveBrigade::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    std::string brigade_name;

    iss >> id >> std::quoted(brigade_name);

    return std::make_shared<LocomotiveBrigade>(id, brigade_name);
}
