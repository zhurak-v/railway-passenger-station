#pragma once
#include "entities/head-department.hpp"
#include "data/repositories/base-repository.hpp"

class HeadDepartmentRepository : public BaseRepository<HeadDepartment> {
public:
    using BaseRepository::BaseRepository;
};
