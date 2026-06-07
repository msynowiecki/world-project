#pragma once
#include <string>
#include <vector>

#include "../../models/Position.h"
#include "../../models/Action.h"

struct LifeSpan {
    int birthTurn;
    int deathTurn;
};

class Environment; 

class Organism {
private:
    int power;
    int initiative;
    Position position;
    std::string species;

    int liveLength;
    int reproductionPower;

    std::vector<LifeSpan> ancestorHistory;

    Environment* environment; 

public:
    Organism(Position position, Environment* environment);
    Organism();

    virtual ~Organism() = default;

    int getPower() const;
    void setPower(int power);

    int getInitiative() const;
    void setInitiative(int initiative);

    Position getPosition() const;
    void setPosition(Position position);

    std::string getSpecies() const;
    void setSpecies(std::string species);

    int getLiveLength() const;
    void setLiveLength(int liveLength);

    int getReproductionPower() const;
    void setReproductionPower(int reproductionPower);

    Environment* getEnvironment() const; 

    const std::vector<LifeSpan>& getAncestorHistory() const;
    void addAncestorHistory(int birthTurn, int deathTurn);

    std::string toString();

    virtual std::vector<Action*> move() = 0;
    virtual std::vector<Action*> action() = 0;
    
    virtual void initialParams() = 0;
    virtual Organism* clone() = 0;

    virtual std::vector<Action*> consequences(Organism* attackingOrganism);

    virtual bool isPlant() const;
    virtual bool isAnimal() const;

    bool ifReproduce();
};