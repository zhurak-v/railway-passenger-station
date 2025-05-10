#pragma once
#include <vector>
#include <memory>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "entities/base.hpp"

std::vector<std::shared_ptr<Base>> loadAllEntitiesFromFolder(const std::string& folder = ".");
void saveEntitiesByType(const std::vector<std::shared_ptr<Base>>& entities);