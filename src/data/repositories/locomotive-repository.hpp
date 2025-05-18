#pragma once
#include "entities/locomotive.hpp"
#include "data/repositories/base-repository.hpp"

class LocomotiveRepository : public BaseRepository<Locomotive> {
public:
    using BaseRepository::BaseRepository;
};
