#include "data/regisetr-entity.hpp"

void registerEntity() {
    EntityFactory::instance().registerClass(HeadDepartment::staticClass(), HeadDepartment::deserialize);
    EntityFactory::instance().registerClass(Department::staticClass(), Department::deserialize);
    EntityFactory::instance().registerClass(Driver::staticClass(), Driver::deserialize);
    EntityFactory::instance().registerClass(Station::staticClass(), Station::deserialize);
    EntityFactory::instance().registerClass(Route::staticClass(), Route::deserialize);
    EntityFactory::instance().registerClass(Trip::staticClass(), Trip::deserialize);
}