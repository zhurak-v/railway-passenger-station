#include "common/utils/generate-id.hpp"

std::string generateId(unsigned int randomCharsCount) {
    static const std::string charset = "0123456789abcdefghijklmnopqrstuvwxyz";

    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    std::stringstream ss;
    ss << std::hex << ms;

    std::string id = ss.str();
    static std::mt19937 gen(std::random_device{}());
    static std::uniform_int_distribution<> dist(0, charset.size() - 1);

    for (unsigned int i = 0; i < randomCharsCount; ++i) {
        id += charset[dist(gen)];
    }

    std::shuffle(id.begin(), id.end(), gen);

    id = "#" + id;

    return id;
}