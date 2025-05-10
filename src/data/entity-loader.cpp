#include "data/entity-loader.hpp"
#include "common/utils/fabric-creator.hpp"

std::vector<std::shared_ptr<Base>> loadAllEntitiesFromFolder(const std::string& folder) {
    std::vector<std::shared_ptr<Base>> result;

    for (const auto& entry : std::filesystem::directory_iterator(folder)) {
        if (!entry.is_regular_file()) continue;

        auto path = entry.path();
        if (path.extension() != ".txt") continue;

        std::string filename = path.filename().string();
        if (filename.find("links") != std::string::npos) continue;

        std::string class_name = filename.substr(0, filename.find('.'));

        std::ifstream file(path);
        std::string line;
        while (std::getline(file, line)) {
            auto entity = EntityFactory::instance().create(class_name, line);
            if (entity)
                result.push_back(entity);
        }
    }

    return result;
}

void saveEntitiesByType(const std::vector<std::shared_ptr<Base>> &entities) {
    std::unordered_map<std::string, std::vector<std::shared_ptr<Base>>> buckets;

    for (const auto &e : entities) {
        buckets[e->getClass()].push_back(e);
    }

    for (const auto &[class_name, group] : buckets) {
        std::ofstream file(class_name + ".txt");
        for (const auto &e : group) {
            file << e->serialize() << "\n";
        }
    }
}