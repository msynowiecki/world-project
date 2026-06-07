#include "Organism.h"
#include "../../Environment.h"

Organism::Organism(Position position, Environment* environment) {
    this->power = 0;
    this->initiative = 0;
    this->position = position;
    this->species = "O";

    this->liveLength = 0;
    this->reproductionPower = 0;
    
    this->environment = environment;
}

Organism::Organism() 
    : power(0), initiative(0), position(0, 0), species("O"), 
      liveLength(0), reproductionPower(0), environment(nullptr) {}

int Organism::getPower() const { return this->power; }
void Organism::setPower(int power) { this->power = power; }

int Organism::getInitiative() const { return this->initiative; }
void Organism::setInitiative(int initiative) { this->initiative = initiative; }

Position Organism::getPosition() const { return this->position; }
void Organism::setPosition(Position position) { this->position = position; }

std::string Organism::getSpecies() const { return this->species; }
void Organism::setSpecies(std::string species) { this->species = species; }

int Organism::getLiveLength() const { return this->liveLength; }
void Organism::setLiveLength(int liveLength) { this->liveLength = liveLength; }

int Organism::getReproductionPower() const { return this->reproductionPower; }
void Organism::setReproductionPower(int reproductionPower) { this->reproductionPower = reproductionPower; }

Environment* Organism::getEnvironment() const { return this->environment; } 

const std::vector<LifeSpan>& Organism::getAncestorHistory() const { 
    return this->ancestorHistory; 
}

void Organism::addAncestorHistory(int birthTurn, int deathTurn) {
    LifeSpan newSpan = { birthTurn, deathTurn };
    this->ancestorHistory.push_back(newSpan);
}

std::string Organism::toString() {
    std::string historyString = ", history: [";
    for (size_t iterator = 0; iterator < this->ancestorHistory.size(); iterator++) {
        historyString += "(" + std::to_string(this->ancestorHistory[iterator].birthTurn) + "->" + std::to_string(this->ancestorHistory[iterator].deathTurn) + ")";
        if (iterator < this->ancestorHistory.size() - 1) {
            historyString += ", ";
        }
    }
    historyString += "]";

    return "{ species: " + this->getSpecies() + 
        ", power: " + std::to_string(getPower()) + 
        ", initiative: " + std::to_string(getInitiative()) + 
        ", position: " + getPosition().toString() + 
        ", liveLength: " + std::to_string(getLiveLength()) +
        ", reproductionPower: " + std::to_string(getReproductionPower()) +
        historyString + "}";
}

std::vector<Action> Organism::consequences(Organism* attackingOrganism) {
    std::vector<Action> result;
    if (this->getPower() > attackingOrganism->getPower()) {
        result.push_back(Action(ActionMapper::A_REMOVE, Position(-1, -1), 0, attackingOrganism));
    } else {
        result.push_back(Action(ActionMapper::A_REMOVE, Position(-1, -1), 0, this));
    }
    return result;
}

bool Organism::ifReproduce() {
    return this->getPower() >= this->getReproductionPower();
}

bool Organism::isPlant() const { return false; }
bool Organism::isAnimal() const { return false; }