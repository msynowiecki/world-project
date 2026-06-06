#pragma once
#include <vector>

#include "Organism.h"
#include "../../models/Action.h"
#include "../../World.h"

class Plant : public Organism {

public:
    Plant(Position position, World* world);

    virtual ~Plant() = default;

    std::vector<Action> move() override;
    std::vector<Action> action() override;

protected:
    std::vector<Position> getFreeNeighboringPosition(Position position);
};