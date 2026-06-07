#pragma once

#include "../base/Animal.h"

class Wolf : public Animal {

public:
    Wolf(Position position, Environment* environment);

    void initialParams() override;
    Organism* clone() override;
    
    std::vector<Action> move() override;
    std::vector<Position> getNeighboringPosition() override;
};