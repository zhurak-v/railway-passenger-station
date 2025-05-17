#pragma once

#include "entities/base.hpp"
#include "common/date/date.hpp"
#include "entities/ticket-status.hpp"

class Ticket : public Base
{
private:
    double price;
    Date purchased_at;
    TicketStatus status;

public:
    Ticket(
        const std::string& id,
        const double price,
        const Date& purchased_at = Date(0, 0),
        const TicketStatus& status = TicketStatus()
    );
    ~Ticket() = default;

public:
    double getPrice() const;
    Date getPurchasedAt() const;

    bool getStatus() const;
    Date getReturnedAt() const;
    
public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Ticket> deserialize(const std::string &data);
};
