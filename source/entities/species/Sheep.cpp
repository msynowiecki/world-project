#include "Sheep.h"
#include "../../World.h"

Sheep::Sheep(Position position, World* world) : Animal(position, world) {
    this->initialParams();
}

void Sheep::initialParams() {
    this->setPower(3);
    this->setInitiative(3);
    this->setLiveLength(10);
    this->setReproductionPower(6);
    this->setSpecies("S");
}

Organism* Sheep::clone() {
    return new Sheep(*this);
}

std::vector<Position> Sheep::getNeighboringPosition() {
    std::vector<Position> neighbors = this->getWorld()->getNeighboringPositions(this->getPosition());

    return this->getWorld()->filterPositionsWithoutAnimals(neighbors);
}