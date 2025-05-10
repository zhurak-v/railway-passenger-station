#include <iostream>
#include "common/relation/relation.hpp"

#include "entities/head-department.hpp"
#include "entities/department.hpp"

#include "common/utils/fabric-creator.hpp"

#include "data/entity-loader.hpp"
#include "data/link-loader.hpp"

#include <cmath>

int main() {
    // ### Register entities ###
    EntityFactory::instance().registerClass(HeadDepartment::staticClass(), HeadDepartment::deserialize);
    EntityFactory::instance().registerClass(HeadDepartment::staticClass(), Department::deserialize);


    // ### Creating entities with relations and saving to files ###
    auto headDepartment = std::make_shared<HeadDepartment>("#hdp-73946", "Andryi", true, 35, 10, 2, 40000);
    auto department = std::make_shared<Department>("#dpm-18956", "IT");

    auto headDepartment2 = std::make_shared<HeadDepartment>("#hdp-33446", "Sophia", false, 25, 3, 1, 20000);
    auto department2 = std::make_shared<Department>("#dpm-55954", "Marketing");

    OneToOne<HeadDepartment, Department> headDepartment_to_deoartment;
    headDepartment_to_deoartment.link(headDepartment, department);
    headDepartment_to_deoartment.link(headDepartment2, department2);

    
    saveLinks(headDepartment_to_deoartment);
    saveEntitiesByType({headDepartment, department, headDepartment2, department2});

    // ### Loading entities and relations from files ###
    auto loaded_entities = loadAllEntitiesFromFolder();

    std::vector<std::shared_ptr<HeadDepartment>> headDepartments;
    std::vector<std::shared_ptr<Department>> departments;

    for (const auto& entity : loaded_entities) {
        if (auto headDepartment = std::dynamic_pointer_cast<HeadDepartment>(entity)) {
            headDepartments.push_back(std::move(headDepartment));
        } else if (auto department = std::dynamic_pointer_cast<Department>(entity)) {
            departments.push_back(std::move(department));
        }
    }

    OneToOne<HeadDepartment, Department> headDepartment_to_department;
    loadAllLinks(headDepartment_to_department, headDepartments, departments);

    for (const auto& headDepartment : headDepartments) {
        if (auto department = headDepartment_to_department.getLinkedB(headDepartment)) {
            std::cout << headDepartment->getFullName() << " -> " << department->getDepartmentName() << "\n";
        }
    }

    return 0;
}