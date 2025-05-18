#pragma once
#include "entities/trip.hpp"
#include "data/repositories/base-repository.hpp"

class TripRepository : public BaseRepository<Trip> {
public:
    using BaseRepository::BaseRepository;
};
