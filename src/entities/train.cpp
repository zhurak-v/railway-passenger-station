#include "entities/train.hpp"

Train::Train(
    const std::string& id,
    const TrainType& train_type
) : Base(id), train_type(train_type) {}

TrainType Train::getTrainType() const {
    return train_type;
}

std::string Train::staticClass()
{
    return "Train";
}
std::string Train::getClass() const { 
    return staticClass();
}