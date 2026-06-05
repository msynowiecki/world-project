#pragma once
#include <string>
#include <vector>

#include "../../models/Position.h"
#include "../../models/Action.h"
#include "../../World.h"

using namespace std;

struct LifeSpan {
    int birthTurn;
    int deathTurn;
};

class Organism {

private:
	int power;
	int iniciative;
	Position position;
	string species;

	int liveLength;
	int reproductionPower;

	LifeSpan* ancestorHistory;
	int ancestorHistorySize;

	World* world;

public:
	Organism(Position position, World* world);
	Organism();

	Organism(const Organism& other);
	Organism(Organism&& other) noexcept;

	Organism& operator=(const Organism& other);
	Organism& operator=(Organism&& other) noexcept;

	virtual ~Organism();

	int getPower();
	void setPower(int power);

	int getInitiative();
	void setInitiative(int initiative);

	Position getPosition();
	void setPosition(Position position);

	string getSpecies();
	void setSpecies(string species);

	int getLiveLength();
	void setLiveLength(int liveLength);

	int getReproductionPower();
	void setReproductionPower(int reproductionPower);

	World* getWorld();

	LifeSpan* getAncestorHistory();

	void addAncestorHistory(int birthTurn, int deathTurn);

	string toString();

	virtual void move() = 0;
	virtual void action() = 0;
	virtual void initialParams() = 0;
	virtual Organism* clone() = 0;

	vector<Action> consequences(Organism* attackingOrganism);
    bool ifReproduce();
};