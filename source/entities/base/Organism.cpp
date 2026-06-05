#include <vector>
#include "Organism.h"

Organism::Organism(Position position, World* world) {
	this->power = 0;
    this->iniciative = 0;
	this->position = position;
	this->species = "O";

    this->liveLength = 0;
    this->reprodctionPower = 0;

	this->ancestorHistory = nullptr;
    this->ancestorHistorySize = 0;

    this->world = world;
}

Organism::Organism() : power(0), iniciative(0), position(0, 0), species("O"), liveLength(0), reprodctionPower(0), ancestorHistory(nullptr), ancestorHistorySize(0), world(nullptr) {}

Organism::Organism(const Organism& other) {
    this->power = other.power;
    this->iniciative = other.iniciative;
    this->position = other.position;
    this->species = other.species;

    this->liveLength = other.liveLength;
    this->reprodctionPower = other.reprodctionPower;

    this->ancestorHistorySize = other.ancestorHistorySize;

    this->world = other.world;

    if (other.ancestorHistory != nullptr) {
        this->ancestorHistory = new LifeSpan[other.ancestorHistorySize];

        for (int iterator = 0; iterator < other.ancestorHistorySize; iterator++) {
            this->ancestorHistory[iterator] = other.ancestorHistory[iterator];
        }
    } else {
        this->ancestorHistory = nullptr;
    }
}

Organism::Organism(Organism&& other) noexcept {
    this->power = other.power;
    this->iniciative = other.iniciative;
    this->position = other.position;
    this->species = other.species;

    this->liveLength = other.liveLength;
    this->reprodctionPower = other.reprodctionPower;

    this->ancestorHistory = other.ancestorHistory;
    this->ancestorHistorySize = other.ancestorHistorySize;

    this->world = other.world;
    
    other.ancestorHistory = nullptr;
    other.ancestorHistorySize = 0;
}

Organism& Organism::operator=(const Organism& other) {
    if (this == &other) return *this;

    delete[] this->ancestorHistory;

    this->power = other.power;
    this->iniciative = other.iniciative;
    this->position = other.position;
    this->species = other.species;

    this->liveLength = other.liveLength;
    this->reprodctionPower = other.reprodctionPower;

    this->ancestorHistorySize = other.ancestorHistorySize;

    this->world = other.world;

    if (other.ancestorHistory != nullptr) {
        this->ancestorHistory = new LifeSpan[other.ancestorHistorySize];

        for (int iterator = 0; iterator < other.ancestorHistorySize; iterator++) {
            this->ancestorHistory[iterator] = other.ancestorHistory[iterator];
        }
    } else {
        this->ancestorHistory = nullptr;
    }

    return *this;
}

Organism& Organism::operator=(Organism&& other) noexcept {
    if (this == &other) return *this;

    delete[] this->ancestorHistory;

    this->power = other.power;
    this->iniciative = other.iniciative;
    this->position = other.position;
    this->species = other.species;

    this->liveLength = other.liveLength;
    this->reprodctionPower = other.reprodctionPower;

    this->ancestorHistory = other.ancestorHistory;
    this->ancestorHistorySize = other.ancestorHistorySize;

    this->world = other.world;

    other.ancestorHistory = nullptr;
    other.ancestorHistorySize = 0;

    return *this;
}

Organism::~Organism() { delete[] ancestorHistory; }

int Organism::getPower() { return this->power; }
void Organism::setPower(int power) { this->power = power; }

int Organism::getInitiative() { return this->iniciative; }
void Organism::setInitiative(int initiative) { this->iniciative = initiative; }

Position Organism::getPosition(){ return this->position; }
void Organism::setPosition(Position position) { this->position = position; }

string Organism::getSpecies() { return this->species; }
void Organism::setSpecies(string species) { this->species = species; }

int Organism::getLiveLength() { return this->liveLength; }
void Organism::setLiveLength(int liveLength) { this->liveLength = liveLength; }

int Organism::getReprodctionPower() { return this->reprodctionPower; }
void Organism::setReprodctionPower(int reprodctionPower) { this->reprodctionPower = reprodctionPower; }

World* Organism::getWorld() { return this->world; }

LifeSpan* Organism::getAncestorHistory() { return this->ancestorHistory; }

void Organism::addAncestorHistory(int birth, int death){
    LifeSpan* newHistory = new LifeSpan[this->ancestorHistorySize + 1];

    for (int iterator = 0; iterator < this->ancestorHistorySize; iterator++) {
        newHistory[iterator] = this->ancestorHistory[iterator];
    }

    newHistory[this->ancestorHistorySize].birthTurn = birth;
    newHistory[this->ancestorHistorySize].deathTurn = death;

    delete[] this->ancestorHistory;
    this->ancestorHistory = newHistory;
    this->ancestorHistorySize++;
}

string Organism::toString() {
    string historyString = ", history: [";

    for(int iterator=0; iterator<ancestorHistorySize; iterator++) {
        historyString += "(" + to_string(ancestorHistory[iterator].birthTurn) + "->" + to_string(ancestorHistory[iterator].deathTurn) + ")";
        
        if(iterator < ancestorHistorySize - 1) historyString += ", ";
    }
    historyString += "]";

    return "{ species: " + this->getSpecies() + 
        ", power: " + to_string(getPower()) + 
        ", initiative: " + to_string(getInitiative()) + 
        ", position: " + getPosition().toString() + 
        ", liveLength: " + to_string(getLiveLength()) +
        ", reproductionPower: " + to_string(getReprodctionPower()) +
        historyString + "}";
}

