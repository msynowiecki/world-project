#include <cstdlib>

#include "Animal.h"
#include "../../Environment.h" 

Animal::Animal(Position position, Environment* environment) : Organism(position, environment) {
    this->lastPosition = position;
}

Position Animal::getLastPosition() const { return this->lastPosition; }
void Animal::setLastPosition(Position value) { this->lastPosition = value; }

std::vector<Action> Animal::move() {
    std::vector<Action> result;
    std::vector<Position> availablePositions = this->getNeighboringPosition();

    if (!availablePositions.empty()) {
        int randomIndex = rand() % availablePositions.size();
        Position newPosition = availablePositions[randomIndex];

        result.push_back(Action(ActionMapper::A_MOVE, newPosition, 0, this));

        this->setLastPosition(this->getPosition());

        Organism* metOrganism = this->getEnvironment()->getOrganismFromPosition(newPosition);
        if (metOrganism != nullptr) {

            std::vector<Action> encounterConsequences = metOrganism->consequences(this);
            result.insert(result.end(), encounterConsequences.begin(), encounterConsequences.end());
        }
    }
    return result;
}

std::vector<Action> Animal::action() {
    std::vector<Action> result;
    std::vector<Position> availablePositions = this->getFreeNeighboringPosition();

    if (this->ifReproduce() && !availablePositions.empty()) {
        int randomIndex = rand() % availablePositions.size();
        Position newAnimalPosition = availablePositions[randomIndex];

        Organism* newAnimal = this->clone();
        newAnimal->initialParams();
        newAnimal->setPosition(newAnimalPosition);

        this->setPower(this->getPower() / 2);

        result.push_back(Action(ActionMapper::A_ADD, newAnimalPosition, 0, newAnimal));
    }
    return result;
}

std::vector<Position> Animal::getFreeNeighboringPosition() {
    if (this->getEnvironment() == nullptr) {
        return std::vector<Position>();
    }

    return this->getEnvironment()->filterFreePositions(this->getEnvironment()->getNeighboringPositions(this->getPosition()));
}

std::vector<Position> Animal::getNeighboringPosition() {
    return this->getEnvironment()->getNeighboringPositions(this->getPosition());
}

bool Animal::isAnimal() const { return true; }
