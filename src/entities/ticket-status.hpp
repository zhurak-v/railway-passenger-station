#pragma once
#include "common/date/date.hpp"

class TicketStatus {
private:
    bool is_returned;
    Date returned_at;

public:
    TicketStatus();
    TicketStatus(bool is_returned, const Date& returned_at);
    ~TicketStatus() = default;

public:
    bool getStatus() const;
    Date getReturnedAt() const;

};