#include <iostream>

#include "Drawer.h"
#include "../World.h"
#include "../models/Position.h"
#include "../entities/base/Organism.h"

void Drawer::draw(const World& world) const {

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::cout << "\nturn: " << world.getTurn() << "\n";

    for (int y = 0; y < world.getWorldY(); ++y) {
        for (int x = 0; x < world.getWorldX(); ++x) {
            Organism* organism = world.getOrganismFromPosition(Position(x, y));

            if (organism != nullptr) {
                std::cout << organism->getSpecies();
            } else {
                std::cout << world.getSeparator();
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}