#pragma once

#include "../World.h"
#include "Drawer.h"

class Turner {

private:
    World& world;
    Drawer drawer;

    void executeTurnLogic();

public:
    Turner(World& world);
    
    void run(int totalTurns);
};