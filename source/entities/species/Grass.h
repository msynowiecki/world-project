#pragma once

#include "../base/Plant.h"

class Grass : public Plant {

public:
    Grass(Position position, World* world);

    void initialParams() override;
    Organism* clone() override;
};