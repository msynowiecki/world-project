#include "Toadstool.h"
#include "../../models/actions/Remove.h"

Toadstool::Toadstool(Position position, Environment* environment) : Plant(position, environment) {
    this->initialParams();
}

void Toadstool::initialParams() {
    this->setPower(0);
    this->setInitiative(0);
    this->setLiveLength(12);
    this->setReproductionPower(4);
    this->setSpecies("T");
}

Organism* Toadstool::clone() {
    return new Toadstool(*this);
}

std::vector<Action*> Toadstool::consequences(Organism* attackingOrganism) {
    std::vector<Action*> result;

    if (this->getPower() > attackingOrganism->getPower()) {
        result.push_back(new Remove(attackingOrganism));
    } else {
        result.push_back(new Remove(this));
        result.push_back(new Remove(attackingOrganism));
    }
    
    return result;
}