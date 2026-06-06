#include <cstdlib>

#include "Wolf.h"
#include "Plant.h"
#include "../../World.h"

Wolf::Wolf(Position position, World* world) : Animal(position, world) {
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

std::vector<Action> Wolf::move() {
    std::vector<Action> result;
    std::vector<Position> availablePositions = this->getNeighboringPosition();

    if (!availablePositions.empty()) {
        int randomIndex = rand() % availablePositions.size();
        Position newPosition = availablePositions[randomIndex];

        result.push_back(Action(ActionMapper::A_MOVE, newPosition, 0, this));
        this->setLastPosition(this->getPosition());

        Organism* metOrganism = this->getWorld()->getOrganismFromPosition(newPosition);
        
        if (metOrganism != nullptr && dynamic_cast<Plant*>(metOrganism) == nullptr) {
            std::vector<Action> encounterConsequences = metOrganism->consequences(this);
            result.insert(result.end(), encounterConsequences.begin(), encounterConsequences.end());
        }
    }
    return result;
}

std::vector<Position> Wolf::getNeighboringPosition() {
    std::vector<Position> baseNeighbors = this->getWorld()->getNeighboringPositions(this->getPosition());
    
    return this->getWorld()->filterPositionsWithOtherSpecies(baseNeighbors, "W");
}