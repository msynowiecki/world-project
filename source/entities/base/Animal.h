#pragma once
#include <vector>

#include "Organism.h"
#include "../../models/Position.h"
#include "../../models/Action.h"
#include "../../World.h"

class Animal : public Organism {
private:
    Position lastPosition;

public:
    Animal(Position position, World* world);

    Position getLastPosition() const;
    void setLastPosition(Position value);

    std::vector<Action> move() override;
    std::vector<Action> action() override;

    std::vector<Position> getFreeNeighboringPosition();
    virtual std::vector<Position> getNeighboringPosition();

    virtual void initialParams() override = 0;
    virtual Organism* clone() override = 0;
};