#include <iostream>
#include <algorithm>

#include "Turner.h"
#include "../entities/base/Organism.h"

bool compareOrganismsExternally(Organism* firstOrganism, Organism* secondOrganism) {
    return firstOrganism->getInitiative() > secondOrganism->getInitiative();
}

Turner::Turner(World& world) : world(world), drawer(Drawer()) {}

void Turner::run(int totalTurns) {
    drawer.draw(world);

    for (int iterator = 0; iterator < totalTurns; ++iterator) {
        std::cin.get();

        this->executeTurnLogic();

        world.makeTurn();
        drawer.draw(world);
    }
}

void Turner::executeTurnLogic() {
    std::vector<Action> actions;
    
    std::vector<Organism*>& organisms = world.getOrganisms();
    std::vector<Organism*>& newOrganisms = world.getNewOrganisms();

    for (size_t iterator = 0; iterator < organisms.size(); ++iterator) {
        Organism* organism = organisms[iterator];
        
        if (world.positionOnBoard(organism->getPosition())) {
            actions = organism->move();
            for (const Action& action : actions) {
                world.makeMove(action);
            }
            actions.clear();

            actions = organism->action();
            for (const Action& action : actions) {
                world.makeMove(action);
            }
            actions.clear();
        }
    }

    std::vector<Organism*> remainingOrganisms;
    for (Organism* organism : organisms) {
        if (world.positionOnBoard(organism->getPosition())) {
            remainingOrganisms.push_back(organism);
        } else {
            delete organism;
        }
    }
    organisms = remainingOrganisms;

    std::vector<Organism*> longLivingOrganisms;
    for (Organism* organism : organisms) {
        if (!world.positionOnBoard(organism->getPosition())) {
            delete organism; 
            continue;
        }

        organism->setLiveLength(organism->getLiveLength() - 1);
        organism->setPower(organism->getPower() + 1);

        if (organism->getLiveLength() < 1) {
            std::cout << organism->getSpecies() << ": died of old age at: " 
                      << organism->getPosition().toString() << std::endl;
            delete organism;
        } else {
            longLivingOrganisms.push_back(organism);
        }
    }
    organisms = longLivingOrganisms;

    for (Organism* organism : newOrganisms) {
        if (world.positionOnBoard(organism->getPosition())) {
            organisms.push_back(organism);
        } else {
            delete organism;
        }
    }
    newOrganisms.clear();

    std::sort(organisms.begin(), organisms.end(), compareOrganismsExternally);
}