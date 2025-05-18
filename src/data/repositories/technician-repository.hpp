#pragma once
#include "entities/technician.hpp"
#include "data/repositories/base-repository.hpp"

class TechnicianRepository : public BaseRepository<Technician> {
public:
    using BaseRepository::BaseRepository;
};