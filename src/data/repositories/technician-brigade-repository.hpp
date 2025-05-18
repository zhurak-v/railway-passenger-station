#pragma once
#include "entities/technician-brigade.hpp"
#include "data/repositories/base-repository.hpp"

class TechnicianBrigadeRepository : public BaseRepository<TechnicianBrigade> {
public:
    using BaseRepository::BaseRepository;
};
