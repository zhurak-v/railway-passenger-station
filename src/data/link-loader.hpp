#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

template <typename A, typename B>
void saveLinks(const OneToOne<A, B>& map, const std::string& filename = A::staticClass() + "-to-" + B::staticClass() + "-links.txt") {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for saving links: " << filename << std::endl;
        return;
    }
    for (const auto& [a_weak, b_weak] : map.getAMap()) {
        auto a = a_weak.lock();
        auto b = b_weak.lock();
        if (a && b) {
            file << a->getId() << " " << b->getId() << "\n";
        }
    }
}

template <typename A, typename B>
void loadAllLinks(
    OneToOne<A, B>& one_to_one,
    const std::vector<std::shared_ptr<A>>& a_list,
    const std::vector<std::shared_ptr<B>>& b_list,
    const std::string& folder = "."
) {
    std::string filename = folder + "/" + A::staticClass() + "-to-" + B::staticClass() + "-links.txt";
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for loading links: " << filename << std::endl;
        return;
    }

    std::unordered_map<std::string, std::shared_ptr<A>> a_map;
    for (const auto& a : a_list) {
        a_map[a->getId()] = a;
    }

    std::unordered_map<std::string, std::shared_ptr<B>> b_map;
    for (const auto& b : b_list) {
        b_map[b->getId()] = b;
    }

    std::string a_id, b_id;
    while (file >> a_id >> b_id) {
        auto a_it = a_map.find(a_id);
        auto b_it = b_map.find(b_id);

        if (a_it != a_map.end() && b_it != b_map.end()) {
            one_to_one.link(a_it->second, b_it->second);
        } else {
            std::cerr << "Warning: Link not found for IDs " << a_id << " and " << b_id << std::endl;
        }
    }
}
