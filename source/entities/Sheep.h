#pragma once

#include "base/Animal.h"

class Sheep : public Animal {

public:
    Sheep(Position position, World* world);

    void initialParams() override;
    Organism* clone() override;

    std::vector<Position> getNeighboringPosition() override;
};