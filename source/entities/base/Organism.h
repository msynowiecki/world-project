#pragma once
#include <string>
#include "../../services/Position.h"

using namespace std;

struct LifeSpan {
    int birthTurn;
    int deathTurn;
};

class Organism {

private:
	int power;
	Position position;
	string species;

	LifeSpan* ancestorHistory;
	int ancestorHistorySize;

public:
	Organism(int power, Position position);
	Organism();

	int getPower();
	void setPower(int power);

	Position getPosition();
	void setPosition(Position position);

	string getSpecies();
	void setSpecies(string species);

	string toString();

	virtual void move(int directionX, int directionY);
};