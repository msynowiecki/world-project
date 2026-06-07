#include <iostream>
#include <cstdlib>
#include <ctime>

#include "source/World.h"
#include "source/models/Position.h"
#include "source/managers/Turner.h" // Dołączamy nasz nowy manager tury

// Dołączenie poszczególnych gatunków
#include "source/entities/species/Grass.h"
#include "source/entities/species/Sheep.h"
#include "source/entities/species/Dandelion.h"
#include "source/entities/species/Wolf.h"
#include "source/entities/species/Toadstool.h"

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    World livingWorld(8, 8);
    
    livingWorld.addOrganism(new Grass(Position(4, 0), &livingWorld));
    livingWorld.addOrganism(new Sheep(Position(0, 0), &livingWorld));
    livingWorld.addOrganism(new Dandelion(Position(0, 4), &livingWorld));
    livingWorld.addOrganism(new Wolf(Position(7, 7), &livingWorld));
    livingWorld.addOrganism(new Toadstool(Position(4, 4), &livingWorld));

    Turner gameController(livingWorld);

    gameController.run(100);

    return 0;
}