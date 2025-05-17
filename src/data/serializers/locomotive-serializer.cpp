#include "entities/locomotive.hpp"
#include "common/date/date.hpp"
#include <iomanip>

std::string Locomotive::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << getManufactureDate().serialize();

    return oss.str();
}

std::shared_ptr<Locomotive> Locomotive::deserialize(const std::string &data)
{
    std::istringstream iss(data);

    std::string id;
    std::string manufacture_date_str;

    iss >> id >> manufacture_date_str;
    
    Date manufacture_date = Date::deserialize(manufacture_date_str);

    return std::make_shared<Locomotive>(id, manufacture_date);
}
