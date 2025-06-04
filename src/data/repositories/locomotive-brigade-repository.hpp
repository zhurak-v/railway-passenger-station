#pragma once
#include "entities/locomotive-brigade.hpp"
#include "data/repositories/base-repository.hpp"

class LocomotiveBrigadeRepository : public BaseRepository<LocomotiveBrigade> {
public:
    using BaseRepository::BaseRepository;
};
