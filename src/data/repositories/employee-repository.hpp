#pragma once
#include "data/repositories/base-repository.hpp"
#include "entities/base-employee.hpp"

class EmployeeRepository : public BaseRepository<Employee> {
public:
    using BaseRepository::BaseRepository;
};
