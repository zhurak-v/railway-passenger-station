#pragma once

#include "common/relation/one-to-one.hpp"
#include "data/loaders/link-loader.hpp"
#include "data/repositories/department-repository.hpp"
#include "data/repositories/head-department-repository.hpp"

class DepartmentToHeadDepartmentSerice {
private:
    DepartmentRepository& department_repository;
    HeadDepartmentRepository& head_department_repository;

private:
    OneToOne<Department, HeadDepartment> department_to_head;

public:
    DepartmentToHeadDepartmentSerice(
        DepartmentRepository& department_repository,
        HeadDepartmentRepository& head_department_repository
    );
    ~DepartmentToHeadDepartmentSerice() = default;

public:
    std::shared_ptr<Department> getDepartmentByHead(std::string& id) const;
    std::shared_ptr<HeadDepartment> getHeadByDepartment(std::string& id) const;
};