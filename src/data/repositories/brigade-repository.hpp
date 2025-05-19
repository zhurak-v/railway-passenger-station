#pragma once
#include "entities/brigade.hpp"
#include "data/repositories/base-repository.hpp"

class BrigadeRepository : public BaseRepository<Brigade> {
public:
    using BaseRepository::BaseRepository;
};
