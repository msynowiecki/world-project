#pragma once

#include "../Action.h"
#include "../Position.h"

class Organism;
class World;

class Move : public Action {

private:
    Organism* organism;
    Position newPosition;

public:
    Move(Organism* organism, const Position& newPosition);

    void execute(World* world) override;
    std::string toString() const override;
};