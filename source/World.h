#pragma once
#include <vector>
#include <string>
#include "models/Position.h"
#include "models/Action.h"

class Organism;

class World {

private:
    int worldX;
    int worldY;
    int turn;
    std::vector<Organism*> organisms;
    std::vector<Organism*> newOrganisms;
    char separator;

public:
    World(int worldX, int worldY);
    ~World();

    int getWorldX() const;
    int getWorldY() const;
    
    int getTurn() const;
    void setTurn(int turn);

    std::vector<Organism*>& getOrganisms();
    void setOrganisms(const std::vector<Organism*>& organisms);

    std::vector<Organism*>& getNewOrganisms();
    void setNewOrganisms(const std::vector<Organism*>& newOrganisms);

    char getSeparator() const;

    void makeTurn();
    void makeMove(const Action& action);
    bool addOrganism(Organism* newOrganism);
    bool positionOnBoard(const Position& position) const;

    Organism* getOrganismFromPosition(const Position& position) const;
    std::vector<Position> getNeighboringPositions(const Position& position) const;
    std::vector<Position> filterFreePositions(const std::vector<Position>& fields) const;
    std::vector<Position> filterPositionsWithoutAnimals(const std::vector<Position>& fields) const;
    std::vector<Position> filterPositionsWithOtherSpecies(const std::vector<Position>& fields, std::string species) const;

    std::string toString() const;
};