#include <cstdlib> // Do obsługi rand()
#include "Animal.h"
#include "../../World.h" 

Animal::Animal(Position position, World* world) : Organism(position, world) {
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

        Organism* metOrganism = this->getWorld()->getOrganismFromPosition(newPosition);
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
    if (this->getWorld() == nullptr) {
        return std::vector<Position>();
    }

    return this->getWorld()->filterFreePositions(this->getWorld()->getNeighboringPositions(this->getPosition()));
}

std::vector<Position> Animal::getNeighboringPosition() {
    return this->getWorld()->getNeighboringPositions(this->getPosition());
}
