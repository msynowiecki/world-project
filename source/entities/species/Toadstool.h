#pragma once

#include "../base/Plant.h"

class Toadstool : public Plant {

public:
    Toadstool(Position position, Environment* environment);

    void initialParams() override;
    Organism* clone() override;
    
    std::vector<Action> consequences(Organism* attackingOrganism) override;
};