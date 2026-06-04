#include "Organism.h"

Organism::Organism(int power, Position position) {
	setPower(power);
	setPosition(position);
	setSpecies("O");

	this->ancestorHistory = nullptr;
    this->ancestorHistorySize = 0;
}

Organism::Organism() : power(0), position(0, 0), species("O"), ancestorHistory(nullptr), ancestorHistorySize(0) {}

Organism::Organism(const Organism& other) {
    this->power = other.power;
    this->position = other.position;
    this->species = other.species;

    this->ancestorHistorySize = other.ancestorHistorySize;

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
    this->position = other.position;
    this->species = other.species;

    this->ancestorHistory = other.ancestorHistory;
    this->ancestorHistorySize = other.ancestorHistorySize;
    
    other.ancestorHistory = nullptr;
    other.ancestorHistorySize = 0;
}

Organism& Organism::operator=(const Organism& other) {
    if (this == &other) return *this;

    delete[] this->ancestorHistory;

    this->power = other.power;
    this->position = other.position;
    this->species = other.species;

    this->ancestorHistorySize = other.ancestorHistorySize;

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
    this->position = other.position;
    this->species = other.species;

    this->ancestorHistory = other.ancestorHistory;
    this->ancestorHistorySize = other.ancestorHistorySize;
    
    other.ancestorHistory = nullptr;
    other.ancestorHistorySize = 0;

    return *this;
}

Organism::~Organism() { delete[] ancestorHistory; }

int Organism::getPower() { return this->power; }
void Organism::setPower(int power) { this->power = power; }

Position Organism::getPosition(){ return this->position; }
void Organism::setPosition(Position position) { this->position = position; }

string Organism::getSpecies() { return this->species; }
void Organism::setSpecies(string species) { this->species = species; }

string Organism::toString() {
	return "{ species: " + this->getSpecies() + 
		", power: " + to_string(getPower()) + 
		", position: " + getPosition().toString() + "}";
}

void Organism::move(int directionX, int directionY) {
	position.move(directionX, directionY);
}

