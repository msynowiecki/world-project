#include "Move.h"
#include "../../entities/base/Organism.h"
#include "../../World.h"

Move::Move(Organism* organism, const Position& newPosition) : organism(organism), newPosition(newPosition) {}

void Move::execute(World* world) { 
    organism->setPosition(newPosition); 
}

std::string Move::toString() const { 
    return "Organism moved to " + newPosition.toString();
}