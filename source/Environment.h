#pragma once
#include <vector>
#include <string>

class Organism;
class Position;

class Environment {

public:
    virtual ~Environment() = default;
    
    virtual Organism* getOrganismFromPosition(const Position& position) const = 0;
    virtual std::vector<Position> getNeighboringPositions(const Position& position) const = 0;
    virtual std::vector<Position> filterFreePositions(const std::vector<Position>& fields) const = 0;
    virtual std::vector<Position> filterPositionsWithOtherSpecies(const std::vector<Position>& fields, const std::string& species) const = 0;
    virtual std::vector<Position> filterPositionsWithoutAnimals(const std::vector<Position>& fields) const = 0;
};