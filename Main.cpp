#include <iostream>
#include <cstdlib>

#include "source/World.h"
#include "source/models/Position.h"
#include "source/entities/Grass.h"
#include "source/entities/Sheep.h"

int main() {
    srand(time(NULL));

    World livingWorld(5, 5);

    Organism* grass1 = new Grass(Position(2, 2), &livingWorld);
    livingWorld.addOrganism(grass1);

    Organism* grass2 = new Grass(Position(2, 4), &livingWorld);
    livingWorld.addOrganism(grass2);

    Organism* sheep1 = new Sheep(Position(0, 0), &livingWorld);
    livingWorld.addOrganism(sheep1);

    system("clear"); 

    std::cout << livingWorld.toString() << std::endl;

    for (int iterator = 0; iterator < 20; ++iterator) {
        std::cin.get(); 

        system("clear"); 

        livingWorld.makeTurn();
        std::cout << livingWorld.toString() << std::endl;
    }

    return 0;
}