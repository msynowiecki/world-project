#include "Grass.h"

Grass::Grass(Position position, World* world) : Plant(position, world) {
    this->initialParams();
}

void Grass::initialParams() {
    this->setPower(0);
    this->setInitiative(0);
    this->setLiveLength(6);
    this->setReproductionPower(3);
    this->setSpecies("G");
}

Organism* Grass::clone() {
    return new Grass(*this);
}