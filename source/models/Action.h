#pragma once
#include <string>
#include "Position.h"

using namespace std;

class Organism; 

enum class ActionMapper {
    A_MOVE = 0,
    A_REMOVE = 1,
    A_ADD = 2,
    A_INCREASEPOWER = 3
};

class Action {

private:
    ActionMapper actionType;
    Position position;
    int value;

    Organism* organism;

public:
    Action(ActionMapper action, Position position, int value, Organism* organism);

    ActionMapper getActionType() const;
    Position getPosition() const;
    int getValue() const;
    
    Organism* getOrganism() const;

    string toString() const;
};