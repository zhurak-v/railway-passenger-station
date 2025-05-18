#pragma once
#include <vector>
#include "entities/base.hpp"

enum class TrainType {
    FAST = 120,
    PASSANGERS = 60
};

class Train : public Base
{
private:
    TrainType train_type;

public:
    Train(
        const std::string& id,
        const TrainType& train_type
    );
    ~Train() = default;

public:
    TrainType getTrainType() const;
    
public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Train> deserialize(const std::string &data);
};
