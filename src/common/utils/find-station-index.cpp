#include "common/utils/find-station-index.hpp"

int findStationIndex(const std::vector<std::shared_ptr<Station>>& stations, const std::string& station_id) {
    for (int i = 0; i < stations.size(); ++i) {
        if (stations[i]->getId() == station_id) {
            return i;
        }
    }
    return -1;
}