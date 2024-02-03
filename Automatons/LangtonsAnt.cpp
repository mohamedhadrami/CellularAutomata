#include "LangtonsAnt.h"

LangtonsAnt::LangtonsAnt(int width, int height) : CellularAutomaton(width, height) {
    initialize();
}

void LangtonsAnt::initialize() {
    // Set the initial state for Langton's Ant automaton
    grid[height / 2][width / 2] = true;  // Ant starts in the center
    antX = width / 2;
    antY = height / 2;
    antDirection = AntDirection::UP;
}

void LangtonsAnt::update() {
    // Move the ant based on Langton's Ant rules
    if (grid[antY][antX]) {
        // Turn right and flip the cell
        antDirection = static_cast<AntDirection>((static_cast<int>(antDirection) + 1) % 4);
        grid[antY][antX] = !grid[antY][antX];
    } else {
        // Turn left and flip the cell
        antDirection = static_cast<AntDirection>((static_cast<int>(antDirection) + 3) % 4);
        grid[antY][antX] = !grid[antY][antX];
    }

    // Move the ant forward
    moveAnt();
}

void LangtonsAnt::moveAnt() {
    switch (antDirection) {
        case AntDirection::UP:
            antY = (antY - 1 + height) % height;
            break;
        case AntDirection::RIGHT:
            antX = (antX + 1) % width;
            break;
        case AntDirection::DOWN:
            antY = (antY + 1) % height;
            break;
        case AntDirection::LEFT:
            antX = (antX - 1 + width) % width;
            break;
    }
}
