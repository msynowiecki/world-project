#include "Sheep.h"
#include "../../Environment.h"

Sheep::Sheep(Position position, Environment* environment) : Animal(position, environment) {
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
    std::vector<Position> neighbors = this->getEnvironment()->getNeighboringPositions(this->getPosition());

    return this->getEnvironment()->filterPositionsWithoutAnimals(neighbors);
}