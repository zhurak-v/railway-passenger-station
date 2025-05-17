#include "entities/train.hpp"
#include <iomanip>
#include <sstream>

std::string Train::serialize() const
{
    std::ostringstream oss;
    oss << getId() << " "
        << static_cast<int>(getTrainType());

    return oss.str();
}

std::shared_ptr<Train> Train::deserialize(const std::string &data)
{
    std::istringstream iss(data);

    std::string id;
    int train_type;

    iss >> id >> train_type;
    
    return std::make_shared<Train>(id, static_cast<TrainType>(train_type));
}
