#include "entities/brigade.hpp"
#include <iomanip>

std::string Brigade::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " " << 
    std::quoted(getBrigadeName()) << " " << 
    std::quoted(getSpecialization());

    return oss.str();
}

std::shared_ptr<Brigade> Brigade::deserialize(const std::string &data)
{
    std::istringstream iss(data);
    std::string id;
    std::string brigade_name;
    std::string specialization;

    iss >> id >> std::quoted(brigade_name) >> std::quoted(specialization);

    return std::make_shared<Brigade>(id, brigade_name, specialization);
}
