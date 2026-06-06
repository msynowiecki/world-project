#include <iostream>
#include <cstdlib>
#include <ctime>

#include "source/World.h"
#include "source/models/Position.h"

#include "source/entities/species/Grass.h"
#include "source/entities/species/Sheep.h"
#include "source/entities/species/Dandelion.h"
#include "source/entities/species/Wolf.h"
#include "source/entities/species/Toadstool.h"

int main() {
    srand(time(NULL));

    World livingWorld(8, 8);

    Organism* grass = new Grass(Position(4, 0), &livingWorld);
    livingWorld.addOrganism(grass);

    Organism* sheep = new Sheep(Position(0, 0), &livingWorld);
    livingWorld.addOrganism(sheep);

    Organism* dandelion = new Dandelion(Position(0, 4), &livingWorld);
    livingWorld.addOrganism(dandelion);

    Organism* wolf = new Wolf(Position(7, 7), &livingWorld);
    livingWorld.addOrganism(wolf);

    Organism* toadstool = new Toadstool(Position(4, 4), &livingWorld);
    livingWorld.addOrganism(toadstool);

    system("clear");

    std::cout << livingWorld.toString() << std::endl;

    for (int iterator = 0; iterator < 100; ++iterator) {
        std::cin.get();

        system("clear");

        livingWorld.makeTurn();
        std::cout << livingWorld.toString() << std::endl;
    }

    return 0;
}