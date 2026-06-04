#pragma once
#include <string>
#include "Organism.h"

struct LifeSpan {
	int birthTurn;
	int deathTurn;
};

Organism::Organism(int power, Position position) {
	setPower(power);
	setPosition(position);
	setSpecies("O");
}

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

