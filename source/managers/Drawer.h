#pragma once

#include <string>

class World;

class Drawer {

public:
    void draw(const World& world) const;
};