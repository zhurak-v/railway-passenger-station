#include "entities/ticket-status.hpp"

TicketStatus::TicketStatus() : is_returned(false), returned_at(Date(0, 0)) {};
TicketStatus::TicketStatus(bool is_returned, const Date &returned_at)
    : is_returned(is_returned), returned_at(returned_at) {};

bool TicketStatus::getStatus() const
{
    return is_returned;
}

Date TicketStatus::getReturnedAt() const
{
    return returned_at;
}