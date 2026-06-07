#pragma once
#include <vector>

#include "Organism.h"
#include "../../models/Action.h"

class Environment;

class Plant : public Organism {

public:
    Plant(Position position, Environment* environment);

    virtual ~Plant() = default;

    std::vector<Action*> move() override;
    std::vector<Action*> action() override;

protected:
    std::vector<Position> getFreeNeighboringPosition();

    bool isPlant() const override;
};