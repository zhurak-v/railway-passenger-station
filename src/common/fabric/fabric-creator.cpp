
#include "common/fabric/fabric-creator.hpp"

EntityFactory& EntityFactory::instance() {
    static EntityFactory inst;
    return inst;
}

void EntityFactory::registerClass(const std::string& class_name, Creator creator) {
    creators[class_name] = creator;
}

std::shared_ptr<Base> EntityFactory::create(const std::string& class_name, const std::string& data) const {
    auto it = creators.find(class_name);
    if (it != creators.end()) {
        return (it->second)(data);
    }
    return nullptr;
}
