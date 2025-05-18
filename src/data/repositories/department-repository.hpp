#pragma once
#include "entities/department.hpp"
#include "data/repositories/base-repository.hpp"

class DepartmentRepository : public BaseRepository<Department> {
public:
    using BaseRepository::BaseRepository;
};
