#pragma once

#include "../Action.h"
#include "../Position.h"

class Organism;
class World;

class Add : public Action {

private:
    Organism* newOrganism;

public:
    Add(Organism* newOrganism);

    void execute(World* world) override;
    std::string toString() const override;
};