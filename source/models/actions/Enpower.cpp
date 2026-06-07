#include "Enpower.h"
#include "../../entities/base/Organism.h"
#include "../../World.h"

Enpower::Enpower(Organism* organism, int value) 
    : organism(organism), value(value) {}

void Enpower::execute(World* world) {
    organism->setPower(organism->getPower() + value);
}

std::string Enpower::toString() const {
    return organism->getSpecies() + " power increased by " + std::to_string(value);
}