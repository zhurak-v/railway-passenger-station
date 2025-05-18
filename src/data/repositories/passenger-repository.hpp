#pragma once
#include "entities/passenger.hpp"
#include "data/repositories/base-repository.hpp"

class PassengerRepository : public BaseRepository<Passenger> {
public:
    using BaseRepository::BaseRepository;
};
