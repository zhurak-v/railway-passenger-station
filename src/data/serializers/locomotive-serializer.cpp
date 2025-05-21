#include "entities/locomotive.hpp"
#include "common/date/date.hpp"
#include <iomanip>

std::string Locomotive::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << getManufactureDate().serialize() << " ";

    oss << passed_tech_inspection.size() << " ";
    for (const auto& date : passed_tech_inspection) {
        oss << date.serialize() << " ";
    }

    oss << repairs.size() << " ";
    for (const auto& date : repairs) {
        oss << date.serialize() << " ";
    }

    oss << completed_routes << " " << completed_routes_before_repair;

    return oss.str();
}

std::shared_ptr<Locomotive> Locomotive::deserialize(const std::string &data)
{
    std::istringstream iss(data);

    std::string id, dateStr;
    iss >> id >> dateStr;

    Date manufacture_date = Date::deserialize(dateStr);

    size_t pti_count;
    iss >> pti_count;
    std::vector<Date> passed_tech_inspection;
    for (size_t i = 0; i < pti_count; ++i) {
        std::string pti_date_str;
        iss >> pti_date_str;
        passed_tech_inspection.push_back(Date::deserialize(pti_date_str));
    }

    size_t repairs_count;
    iss >> repairs_count;
    std::vector<Date> repairs;
    for (size_t i = 0; i < repairs_count; ++i) {
        std::string repair_date_str;
        iss >> repair_date_str;
        repairs.push_back(Date::deserialize(repair_date_str));
    }

    int completed_routes;
    int completed_routes_before_repair;
    iss >> completed_routes >> completed_routes_before_repair;

    return std::make_shared<Locomotive>(
        id,
        manufacture_date,
        passed_tech_inspection,
        repairs,
        completed_routes,
        completed_routes_before_repair
    );
}