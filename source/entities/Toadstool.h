#pragma once

#include "base/Plant.h"

class Toadstool : public Plant {

public:
    Toadstool(Position position, World* world);

    void initialParams() override;
    Organism* clone() override;
    
    std::vector<Action> consequences(Organism* attackingOrganism) override;
};