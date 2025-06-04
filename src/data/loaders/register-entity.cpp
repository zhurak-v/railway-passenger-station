#include "data/loaders/regisetr-entity.hpp"

void registerEntity() {
    EntityFactory::instance().registerClass(Driver::staticClass(), Driver::deserialize);
    EntityFactory::instance().registerClass(Locomotive::staticClass(), Locomotive::deserialize);
    EntityFactory::instance().registerClass(HeadDepartment::staticClass(), HeadDepartment::deserialize);
    EntityFactory::instance().registerClass(Department::staticClass(), Department::deserialize);
    EntityFactory::instance().registerClass(Route::staticClass(), Route::deserialize);
    EntityFactory::instance().registerClass(Trip::staticClass(), Trip::deserialize);
    EntityFactory::instance().registerClass(Station::staticClass(), Station::deserialize);
    EntityFactory::instance().registerClass(Ticket::staticClass(), Ticket::deserialize);
    EntityFactory::instance().registerClass(Technician::staticClass(), Technician::deserialize);
    EntityFactory::instance().registerClass(Staff::staticClass(), Staff::deserialize);
    EntityFactory::instance().registerClass(TechnicianBrigade::staticClass(), TechnicianBrigade::deserialize);
    EntityFactory::instance().registerClass(LocomotiveBrigade::staticClass(), LocomotiveBrigade::deserialize);
    EntityFactory::instance().registerClass(Train::staticClass(), Train::deserialize);
}