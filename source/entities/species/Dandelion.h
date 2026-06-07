#pragma once

#include "../base/Plant.h"

class Dandelion : public Plant {

public:
    Dandelion(Position position, Environment* environment);

    void initialParams() override;
    Organism* clone() override;
};