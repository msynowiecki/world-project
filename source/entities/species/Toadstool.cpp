#include "Toadstool.h"

Toadstool::Toadstool(Position position, World* world) : Plant(position, world) {
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

std::vector<Action> Toadstool::consequences(Organism* attackingOrganism) {
    std::vector<Action> result;

    if (this->getPower() > attackingOrganism->getPower()) {
        result.push_back(Action(ActionMapper::A_REMOVE, Position(-1, -1), 0, attackingOrganism));
    } else {
        result.push_back(Action(ActionMapper::A_REMOVE, Position(-1, -1), 0, this));
        result.push_back(Action(ActionMapper::A_REMOVE, Position(-1, -1), 0, attackingOrganism));
    }
    
    return result;
}