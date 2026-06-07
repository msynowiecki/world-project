#pragma once

#include "../Action.h"

class Organism;
class World;

class Remove : public Action {

private:
    Organism* target;

public:
    Remove(Organism* target);

    void execute(World* world) override;
    std::string toString() const override;
};