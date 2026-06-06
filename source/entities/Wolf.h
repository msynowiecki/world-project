#pragma once

#include "Animal.h"

class Wolf : public Animal {

public:
    Wolf(Position position, World* world);

    void initialParams() override;
    Organism* clone() override;
    
    std::vector<Action> move() override;
    std::vector<Position> getNeighboringPosition() override;
};