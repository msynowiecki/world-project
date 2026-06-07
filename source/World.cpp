#include <iostream>
#include <algorithm>

#include "World.h"
#include "entities/base/Organism.h"
#include "entities/base/Plant.h"

World::World(int worldX, int worldY) 
    : worldX(worldX), worldY(worldY), turn(0), separator('.') {}

World::~World() {
    for (Organism* organism : this->organisms) {
        delete organism;
    }
    for (Organism* organism : this->newOrganisms) {
        delete organism;
    }
}

int World::getWorldX() const { return this->worldX; }
int World::getWorldY() const { return this->worldY; }
int World::getTurn() const { return this->turn; }
void World::setTurn(int turn) { this->turn = turn; }
char World::getSeparator() const { return this->separator; }

std::vector<Organism*>& World::getOrganisms() { return this->organisms; }
void World::setOrganisms(const std::vector<Organism*>& organisms) { this->organisms = organisms; }

std::vector<Organism*>& World::getNewOrganisms() { return this->newOrganisms; }
void World::setNewOrganisms(const std::vector<Organism*>& newOrganisms) { this->newOrganisms = newOrganisms; }

void World::makeTurn() {
    this->turn += 1;
}

void World::makeMove(const Action& action) {
    std::cout << action.toString() << std::endl;

    switch (action.getActionType()) {
        case ActionMapper::A_ADD:
            this->newOrganisms.push_back(action.getOrganism());
            break;
            
        case ActionMapper::A_INCREASEPOWER:
            action.getOrganism()->setPower(action.getOrganism()->getPower() + action.getValue());
            break;
            
        case ActionMapper::A_MOVE:
            action.getOrganism()->setPosition(action.getPosition());
            break;
            
        case ActionMapper::A_REMOVE:
            std::cout << action.getOrganism()->getSpecies() << " has been eaten!" << std::endl;
            action.getOrganism()->setPosition(Position(-1, -1));
            break;
    }
}

bool World::addOrganism(Organism* newOrganism) {
    if (newOrganism == nullptr) return false;
    
    Position newOrgPosition = newOrganism->getPosition();

    if (this->positionOnBoard(newOrgPosition)) {
        this->organisms.push_back(newOrganism);

        return true;
    }
    
    return false;
}

bool World::positionOnBoard(const Position& position) const {
    return position.getX() >= 0 && position.getY() >= 0 && 
        position.getX() < this->worldX && position.getY() < this->worldY;
}

Organism* World::getOrganismFromPosition(const Position& position) const {
    for (Organism* organism : this->organisms) {
        if (organism->getPosition().getX() == position.getX() && organism->getPosition().getY() == position.getY()) {
            return organism;
        }
    }
    for (Organism* organism : this->newOrganisms) {
        if (organism->getPosition().getX() == position.getX() && organism->getPosition().getY() == position.getY()) {
            return organism;
        }
    }
    return nullptr;
}

std::vector<Position> World::getNeighboringPositions(const Position& position) const {
    std::vector<Position> result;

    for (int y = -1; y <= 1; ++y) {
        for (int x = -1; x <= 1; ++x) {
            Position pomPosition(position.getX() + x, position.getY() + y);
            if (this->positionOnBoard(pomPosition) && !(y == 0 && x == 0)) {
                result.push_back(pomPosition);
            }
        }
    }
    return result;
}

std::vector<Position> World::filterFreePositions(const std::vector<Position>& fields) const {
    std::vector<Position> result;
    for (const Position& field : fields) {
        if (this->getOrganismFromPosition(field) == nullptr) {
            result.push_back(field);
        }
    }
    return result;
}

std::vector<Position> World::filterPositionsWithoutAnimals(const std::vector<Position>& fields) const {
    std::vector<Position> result;
    for (const Position& field : fields) {
        Organism* currentOrganism = this->getOrganismFromPosition(field);
        if (currentOrganism == nullptr || currentOrganism->isPlant()) {
            result.push_back(field);
        }
    }
    return result;
}

std::vector<Position> World::filterPositionsWithOtherSpecies(const std::vector<Position>& fields, std::string species) const {
    std::vector<Position> result;
    for (const Position& field : fields) {
        Organism* currentOrganism = this->getOrganismFromPosition(field);
        if (currentOrganism == nullptr || currentOrganism->getSpecies() != species) {
            result.push_back(field);
        }
    }
    return result;
}