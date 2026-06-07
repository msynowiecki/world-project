#pragma once

#include "../Action.h"

class Organism;
class World;

class Enpower : public Action {

private:
    Organism* organism;
    int value;

public:
    Enpower(Organism* organism, int value);

    void execute(World* world) override;
    std::string toString() const override;
};