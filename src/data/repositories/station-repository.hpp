#pragma once
#include "entities/station.hpp"
#include "data/repositories/base-repository.hpp"

class StationRepository : public BaseRepository<Station> {
public:
    using BaseRepository::BaseRepository;
};
