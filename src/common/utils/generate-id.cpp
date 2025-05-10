#include <common/utils/generate-id.hpp>
#include <random>
#include <sstream>
#include <cmath>

std::string generateId(const std::string& prefix, int digitCount) {
    if (digitCount <= 0) {
        throw std::invalid_argument("digitCount must be positive");
    }

    int min = static_cast<int>(std::pow(10, digitCount - 1));
    int max = static_cast<int>(std::pow(10, digitCount)) - 1;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    std::ostringstream oss;
    oss << "#" << prefix << "-" << dis(gen);
    return oss.str();
}
