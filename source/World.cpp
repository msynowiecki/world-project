#include <iostream>
#include <algorithm>

#include "World.h"
#include "entities/base/Organism.h"
#include "entities/base/Plant.h"


bool compareOrganisms(Organism* firstOrganism, Organism* secondOrganism) {
    return firstOrganism->getInitiative() > secondOrganism->getInitiative();
}

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

std::vector<Organism*>& World::getOrganisms() { return this->organisms; }
void World::setOrganisms(const std::vector<Organism*>& organisms) { this->organisms = organisms; }

std::vector<Organism*>& World::getNewOrganisms() { return this->newOrganisms; }
void World::setNewOrganisms(const std::vector<Organism*>& newOrganisms) { this->newOrganisms = newOrganisms; }

char World::getSeparator() const { return this->separator; }

void World::makeTurn() {
    std::vector<Action> actions;

    for (size_t iterator = 0; iterator < this->organisms.size(); ++iterator) {
        Organism* organism = this->organisms[iterator];
        
        if (this->positionOnBoard(organism->getPosition())) {
            
            actions = organism->move();

            for (const Action& action : actions) {
                this->makeMove(action);
            }

            actions.clear();
            actions = organism->action();

            for (const Action& action : actions) {
                this->makeMove(action);
            }

            actions.clear();
        }
    }

    std::vector<Organism*> remainingOrganisms;
    for (Organism* organism : this->organisms) {
        if (this->positionOnBoard(organism->getPosition())) {
            remainingOrganisms.push_back(organism);
        } else {
            delete organism;
        }
    }

    this->organisms = remainingOrganisms;

    std::vector<Organism*> longLivingOrganisms;
    for (Organism* organism : this->organisms) {
        organism->setLiveLength(organism->getLiveLength() - 1);
        organism->setPower(organism->getPower() + 1);

        if (organism->getLiveLength() < 1) {
            std::cout << organism->getSpecies() << ": died of old age at: " << organism->getPosition().toString() << std::endl;
            delete organism;
        } else {
            longLivingOrganisms.push_back(organism);
        }
    }

    this->organisms = longLivingOrganisms;

    for (Organism* organism : this->newOrganisms) {
        if (this->positionOnBoard(organism->getPosition())) {
            this->organisms.push_back(organism);
        } else {
            delete organism;
        }
    }

    this->newOrganisms.clear();

    std::sort(this->organisms.begin(), this->organisms.end(), compareOrganisms);

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
            action.getOrganism()->setPosition(Position(-1, -1));
            break;
    }
}

bool World::addOrganism(Organism* newOrganism) {
    if (newOrganism == nullptr) return false;
    
    Position newOrgPosition = newOrganism->getPosition();

    if (this->positionOnBoard(newOrgPosition)) {
        this->organisms.push_back(newOrganism);
        std::sort(this->organisms.begin(), this->organisms.end(), compareOrganisms);

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
        
        if (currentOrganism == nullptr || dynamic_cast<Plant*>(currentOrganism) != nullptr) {
            result.push_back(field);
        }
    }

    return result;
}

std::string World::toString() const {
    std::string result = "\nturn: " + std::to_string(this->turn) + "\n";

    for (int worldY = 0; worldY < this->worldY; ++worldY) {
        for (int worldX = 0; worldX < this->worldX; ++worldX) {

            Organism* organism = this->getOrganismFromPosition(Position(worldX, worldY));

            if (organism != nullptr) {
                result += organism->getSpecies();
            } else {
                result += this->separator;
            }
        }
        result += "\n";
    }
    
    return result;
}