#pragma once

#include <string>

class World;

class Action {

public:
    virtual ~Action() = default;

    virtual void execute(World* world) = 0; 
    
    virtual std::string toString() const = 0;
};