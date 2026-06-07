#include <cstdlib>

#include "Wolf.h"
#include "../base/Plant.h"
#include "../../Environment.h"
#include "../../models/actions/Move.h"
#include "../../models/actions/Remove.h"
#include "../../models/actions/Enpower.h"

Wolf::Wolf(Position position, Environment* environment) : Animal(position, environment) {
    this->initialParams();
}

void Wolf::initialParams() {
    this->setPower(8);
    this->setInitiative(5);
    this->setLiveLength(20);
    this->setReproductionPower(16);
    this->setSpecies("W");
}

Organism* Wolf::clone() {
    return new Wolf(*this);
}

std::vector<Action*> Wolf::move() {
    std::vector<Action*> result;
    std::vector<Position> availablePositions = this->getNeighboringPosition();

    if (!availablePositions.empty()) {
        int randomIndex = rand() % availablePositions.size();
        Position newPosition = availablePositions[randomIndex];

        result.push_back(new Move(this, newPosition));
        this->setLastPosition(this->getPosition());

        Organism* metOrganism = this->getEnvironment()->getOrganismFromPosition(newPosition);
        
        if (metOrganism != nullptr) {
            if (dynamic_cast<Plant*>(metOrganism) == nullptr) {
                std::vector<Action*> encounterConsequences = metOrganism->consequences(this);
                result.insert(result.end(), encounterConsequences.begin(), encounterConsequences.end());
            } else {
                result.push_back(new Remove(metOrganism));
                result.push_back(new Enpower(this, 2));
            }
        }
    }

    return result;
}

std::vector<Position> Wolf::getNeighboringPosition() {
    std::vector<Position> baseNeighbors = this->getEnvironment()->getNeighboringPositions(this->getPosition());
    
    return this->getEnvironment()->filterPositionsWithOtherSpecies(baseNeighbors, "W");
}