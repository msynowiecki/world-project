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
	int initiative;
	Position position;
	string species;

	int liveLength;
	int reproductionPower;

	vector<LifeSpan> ancestorHistory;

	World* world;

public:
	Organism(Position position, World* world);
    Organism();

    virtual ~Organism() = default;

    int getPower() const;
    void setPower(int power);

    int getInitiative() const;
    void setInitiative(int initiative);

    Position getPosition() const;
    void setPosition(Position position);

    string getSpecies() const;
    void setSpecies(string species);

    int getLiveLength() const;
    void setLiveLength(int liveLength);

    int getReproductionPower() const;
    void setReproductionPower(int reproductionPower);

    World* getWorld() const;

    const vector<LifeSpan>& getAncestorHistory() const;

    void addAncestorHistory(int birthTurn, int deathTurn);

    string toString();

    virtual vector<Action> move() = 0;
    virtual vector<Action> action() = 0;
    
    virtual void initialParams() = 0;
    virtual Organism* clone() = 0;

    vector<Action> consequences(Organism* attackingOrganism);
    bool ifReproduce();
};