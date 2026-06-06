#pragma once

#include "Plant.h"

class Dandelion : public Plant {

public:
    Dandelion(Position position, World* world);

    void initialParams() override;
    Organism* clone() override;
};