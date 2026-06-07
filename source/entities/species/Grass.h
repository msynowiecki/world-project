#pragma once

#include "../base/Plant.h"

class Grass : public Plant {

public:
    Grass(Position position, Environment* environment);

    void initialParams() override;
    Organism* clone() override;
};