#include "Action.h"
#include "Position.h"
#include "../../entities/base/Organism.h"

Action::Action(ActionMapper action, Position position, int value, Organism* organism) 
    : actionType(action), position(position), value(value), organism(organism) {}

ActionMapper Action::getActionType() const { return this->actionType; }
Position Action::getPosition() const { return this->position; }
int Action::getValue() const { return this->value; }

Organism* Action::getOrganism() const { return this->organism; }

string Action::toString() const {
    if (this->organism == nullptr) return "Action: No organism target";

    string species = this->organism->getSpecies();
    string organismPositionString = this->organism->getPosition().toString();
    string targetPositionString = this->position.toString();

    switch (this->actionType) {
        case ActionMapper::A_ADD:
            return species + ": add at: " + targetPositionString;
            
        case ActionMapper::A_INCREASEPOWER:
            return species + " increase power: " + to_string(this->value);
            
        case ActionMapper::A_MOVE:
            return species + " move from: " + organismPositionString + " to: " + targetPositionString;
            
        case ActionMapper::A_REMOVE:
            return species + " remove from: " + organismPositionString;
            
        default:
            return "Unknown Action";
    }
}