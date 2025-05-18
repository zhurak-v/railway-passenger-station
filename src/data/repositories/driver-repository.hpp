#pragma once
#include "entities/driver.hpp"
#include "data/repositories/base-repository.hpp"

class DriverRepository : public BaseRepository<Driver> {
public:
    using BaseRepository::BaseRepository;
};
