#include "Dandelion.h"

Dandelion::Dandelion(Position position, Environment* environment) : Plant(position, environment) {
    this->initialParams();
}

void Dandelion::initialParams() {
    this->setPower(0);
    this->setInitiative(0);
    this->setLiveLength(6);
    this->setReproductionPower(2);
    this->setSpecies("D");
}

Organism* Dandelion::clone() {
    return new Dandelion(*this);
}