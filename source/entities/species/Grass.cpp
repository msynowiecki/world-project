#include "Grass.h"

Grass::Grass(Position position, Environment* environment) : Plant(position, environment) {
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