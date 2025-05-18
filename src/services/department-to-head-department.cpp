#include "services/department-to-head-department.hpp"

DepartmentToHeadDepartmentSerice::DepartmentToHeadDepartmentSerice(
    DepartmentRepository& department_repository,
    HeadDepartmentRepository& head_department_repository
) : department_repository(department_repository), 
    head_department_repository(head_department_repository) {
    loadAllLinks(
        this->department_to_head, 
        department_repository.getAll(),
        head_department_repository.getAll()
    );
}

std::shared_ptr<Department> DepartmentToHeadDepartmentSerice::getDepartmentByHead(std::string& id) const {
    const std::shared_ptr<HeadDepartment> head_department = head_department_repository.findById(id);
    return department_to_head.getLinkedA(head_department);
}

std::shared_ptr<HeadDepartment> DepartmentToHeadDepartmentSerice::getHeadByDepartment(std::string& id) const {
    const std::shared_ptr<Department> department = department_repository.findById(id);
    return department_to_head.getLinkedB(department);
}