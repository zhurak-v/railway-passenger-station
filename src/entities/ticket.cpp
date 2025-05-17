#include "entities/ticket.hpp"

Ticket::Ticket(
    const std::string &id,
    const double price,
    const Date &purchased_at,
    const TicketStatus &status) : Base(id),
                                  price(price), purchased_at(purchased_at), status(status) {};

double Ticket::getPrice() const {
    return price;
}

bool Ticket::getStatus() const {
    return status.getStatus();
}

Date Ticket::getPurchasedAt() const {
    return purchased_at;
}

Date Ticket::getReturnedAt() const {
    return status.getReturnedAt();
}

std::string Ticket::staticClass() {
    return "Ticket";
}

std::string Ticket::getClass() const { 
    return staticClass();
}