#include "Add.h"
#include "../../entities/base/Organism.h"
#include "../../World.h"

Add::Add(Organism* newOrganism) : newOrganism(newOrganism) {}

void Add::execute(World* world) {
    world->getNewOrganisms().push_back(newOrganism);
}

std::string Add::toString() const {
    return "New organism added to the world: " + newOrganism->getSpecies();
}