#include <unordered_map>
#include <functional>
#include <memory>
#include <string>
#include "entities/base.hpp"

class EntityFactory {
public:
    using Creator = std::function<std::shared_ptr<Base>(const std::string &)>;

    static EntityFactory &instance() {
        static EntityFactory inst;
        return inst;
    }

    void registerClass(const std::string &class_name, Creator creator) {
        creators[class_name] = creator;
    }

    std::shared_ptr<Base> create(const std::string &class_name, const std::string &data) const {
        auto it = creators.find(class_name);
        if (it != creators.end()) {
            return (it->second)(data);
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, Creator> creators;
};
