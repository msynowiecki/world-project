#include "Plant.h"
#include "../../Environment.h"

Plant::Plant(Position position, Environment* environment) : Organism(position, environment) {}

std::vector<Action> Plant::move() {
    std::vector<Action> result;
    return result;
}

std::vector<Action> Plant::action() {
    std::vector<Action> result;

    if (this->ifReproduce()) {
        std::vector<Position> availablePositions = this->getFreeNeighboringPosition();

        if (!availablePositions.empty()) {
            int randomIndex = rand() % availablePositions.size();
            Position newPosition = availablePositions[randomIndex];

            Organism* newPlant = this->clone();
            newPlant->initialParams();
            newPlant->setPosition(newPosition);

            this->setPower(this->getPower() / 2);

            result.push_back(Action(ActionMapper::A_ADD, newPosition, 0, newPlant));
        }
    }
    return result;
}

std::vector<Position> Plant::getFreeNeighboringPosition() {
    if (this->getEnvironment() == nullptr) {
        return std::vector<Position>();
    }
    
    return this->getEnvironment()->filterFreePositions(this->getEnvironment()->getNeighboringPositions(this->getPosition()));
}

bool Plant::isPlant() const { return true; }