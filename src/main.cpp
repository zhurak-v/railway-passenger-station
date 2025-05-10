#include <iostream>
#include "common/relation/relation.hpp"

#include "entities/head-department.hpp"
#include "entities/department.hpp"

#include "common/utils/fabric-creator.hpp"

#include "data/entity-loader.hpp"
#include "data/link-loader.hpp"

#include <cmath>

int main()
{
    // ### Register entities ###
    EntityFactory::instance().registerClass(HeadDepartment::staticClass(), HeadDepartment::deserialize);
    EntityFactory::instance().registerClass(Department::staticClass(), Department::deserialize);
    // ### Register entities ###

    // One-To-One
    // ### Creating entites with relations and saving to files ###
    auto head = std::make_shared<HeadDepartment>("#hdp-10001", "Anna", false, 40, 12, 3, 30000);
    auto department = std::make_shared<Department>("#dpm-20001", "Legal");

    OneToOne<HeadDepartment, Department> oneToOneRelation;
    oneToOneRelation.link(head, department);

    std::cout << head->getFullName() << " -> "
              << oneToOneRelation.getLinkedB(head)->getDepartmentName() << std::endl;

    saveEntitiesByType({head, department});
    saveLinks(oneToOneRelation);
    // ### Creating entites with relations and saving to files ###

    // ### Loading entites with relations from saved files ###
    // auto loaded_entities = loadAllEntitiesFromFolder();

    // std::vector<std::shared_ptr<HeadDepartment>> heads;
    // std::vector<std::shared_ptr<Department>> departments;

    // for (const auto &entity : loaded_entities)
    // {
    //     if (auto head = std::dynamic_pointer_cast<HeadDepartment>(entity))
    //     {
    //         heads.push_back(head);
    //     }
    //     else if (auto dep = std::dynamic_pointer_cast<Department>(entity))
    //     {
    //         departments.push_back(dep);
    //     }
    // }

    // OneToOne<HeadDepartment, Department> oneToOneRelation;
    // loadAllLinks(oneToOneRelation, heads, departments);

    // for (const auto &head : heads)
    // {
    //     auto linkedDep = oneToOneRelation.getLinkedB(head);
    //     if (linkedDep)
    //     {
    //         std::cout << head->getFullName() << " -> "
    //                   << linkedDep->getDepartmentName() << std::endl;
    //     }
    // }
    // ### Loading entites with relations from saved files ###

    // One To Many
    // ### Creating entities with relations and saving to files ###
    // auto head = std::make_shared<HeadDepartment>("#hdp-10002", "Max", true, 50, 20, 5, 50000);
    // auto dep1 = std::make_shared<Department>("#dpm-20002", "IT");
    // auto dep2 = std::make_shared<Department>("#dpm-20003", "Finance");

    // OneToMany<HeadDepartment, Department> oneToManyRelation;
    // oneToManyRelation.link(head, dep1);
    // oneToManyRelation.link(head, dep2);

    // saveEntitiesByType({head, dep1, dep2});
    // saveLinks(oneToManyRelation);
    // ### Creating entities with relations and saving to files ###

    // ### Loading entities with relations from saved files ###
    // auto loaded_entities = loadAllEntitiesFromFolder();

    // std::vector<std::shared_ptr<HeadDepartment>> heads;
    // std::vector<std::shared_ptr<Department>> departments;

    // for (const auto &entity : loaded_entities)
    // {
    //     if (auto h = std::dynamic_pointer_cast<HeadDepartment>(entity))
    //         heads.push_back(h);
    //     else if (auto d = std::dynamic_pointer_cast<Department>(entity))
    //         departments.push_back(d);
    // }

    // OneToMany<HeadDepartment, Department> oneToManyRelationLoaded;
    // loadAllLinks(oneToManyRelationLoaded, heads, departments);

    // for (const auto &head : heads)
    // {
    //     auto linked = oneToManyRelationLoaded.getLinkedB(head);
    //     if (!linked.empty())
    //     {
    //         std::cout << head->getFullName() << " -> " << std::endl;
    //         for (const auto &dep : linked)
    //         {
    //             std::cout << " - " << dep->getDepartmentName() << std::endl;
    //         }
    //     }
    // }
    // ### Loading entities with relations from saved files ###

    // Many To Many
    // ### Creating entities with relations and saving to files ###
    // auto head1 = std::make_shared<HeadDepartment>("#hdp-10003", "Oleh", true, 38, 8, 4, 28000);
    // auto head2 = std::make_shared<HeadDepartment>("#hdp-10004", "Iryna", false, 42, 15, 6, 35000);

    // auto dep1 = std::make_shared<Department>("#dpm-20004", "Marketing");
    // auto dep2 = std::make_shared<Department>("#dpm-20005", "HR");

    // ManyToMany<HeadDepartment, Department> manyToManyRelation;
    // manyToManyRelation.link(head1, dep1);
    // manyToManyRelation.link(head1, dep2);
    // manyToManyRelation.link(head2, dep2); // one department — two heads

    // saveEntitiesByType({head1, head2, dep1, dep2});
    // saveLinks(manyToManyRelation);
    // ### Creating entities with relations and saving to files ###

    // ### Loading entities with relations from saved files ###
    // auto loaded_entities = loadAllEntitiesFromFolder();

    // std::vector<std::shared_ptr<HeadDepartment>> heads;
    // std::vector<std::shared_ptr<Department>> departments;

    // for (const auto &entity : loaded_entities)
    // {
    //     if (auto h = std::dynamic_pointer_cast<HeadDepartment>(entity))
    //         heads.push_back(h);
    //     else if (auto d = std::dynamic_pointer_cast<Department>(entity))
    //         departments.push_back(d);
    // }

    // ManyToMany<HeadDepartment, Department> manyToManyRelationLoaded;
    // loadAllLinks(manyToManyRelationLoaded, heads, departments);

    // for (const auto &head : heads)
    // {
    //     auto linked = manyToManyRelationLoaded.getLinkedB(head);
    //     if (!linked.empty())
    //     {
    //         std::cout << head->getFullName() << " co-manages:\n";
    //         for (const auto &dep : linked)
    //         {
    //             std::cout << " - " << dep->getDepartmentName() << std::endl;
    //         }
    //     }
    // }
    // ### Loading entities with relations from saved files ###

    return 0;
}