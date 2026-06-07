#include "Remove.h"
#include "../../entities/base/Organism.h"
#include "../Position.h"
#include "../../World.h"

Remove::Remove(Organism* target) : target(target) {}

void Remove::execute(World* world) {
    target->setPosition(Position(-1, -1));
}

std::string Remove::toString() const {
    return target->getSpecies() + " has been eaten!";
}