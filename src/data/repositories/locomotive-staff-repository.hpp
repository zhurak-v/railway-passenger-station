#pragma once
#include "entities/locomotive-staff.hpp"
#include "data/repositories/base-repository.hpp"

class StaffRepository : public BaseRepository<Staff> {
public:
    using BaseRepository::BaseRepository;
};