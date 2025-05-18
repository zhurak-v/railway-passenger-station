#pragma once
#include "entities/ticket.hpp"
#include "data/repositories/base-repository.hpp"

class TicketRepository : public BaseRepository<Ticket> {
public:
    using BaseRepository::BaseRepository;
};
