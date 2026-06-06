#include "Plant.h"

Plant::Plant(Position position, World* world) : Organism(position, world) {}

std::vector<Action> Plant::move() {
    std::vector<Action> result;
    return result;
}

std::vector<Action> Plant::action() {
    std::vector<Action> result;

    if (this->ifReproduce()) {
        std::vector<Position> freePositions = this->getFreeNeighboringPosition(this->getPosition());

        if (!freePositions.empty()) {
            int randomIndex = rand() % freePositions.size();
            Position newPosition = freePositions[randomIndex];

            Organism* newPlant = this->clone();
            newPlant->initialParams();
            newPlant->setPosition(newPosition);

            this->setPower(this->getPower() / 2);

            result.push_back(Action(ActionMapper::A_ADD, newPosition, 0, newPlant));
        }
    }
    return result;
}

std::vector<Position> Plant::getFreeNeighboringPosition(Position position) {
    if (this->getWorld() == nullptr) {
        return std::vector<Position>();
    }
    
    return this->getWorld()->filterFreePositions(this->getWorld()->getNeighboringPositions(position));
}