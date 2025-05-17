#include "entities/ticket.hpp"
#include "common/date/date.hpp"
#include <iomanip>

std::string Ticket::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << getPrice() << " "
        << getPurchasedAt().serialize() << " "
        << getStatus() << " "
        << getReturnedAt().serialize();

    return oss.str();
}

std::shared_ptr<Ticket> Ticket::deserialize(const std::string& data)
{
    std::istringstream iss(data);

    std::string id;
    double price;
    std::string purchased_str;
    bool is_returned;
    std::string returned_str;

    iss >> id >> price >> purchased_str >> is_returned >> returned_str;

    Date purchased_at = Date::deserialize(purchased_str);
    Date returned_at = Date::deserialize(returned_str);

    TicketStatus status = TicketStatus(is_returned, returned_at);

    return std::make_shared<Ticket>(id, price, purchased_at, status);
}