#include "Rule30.h"

Rule30::Rule30(int width, int height) : CellularAutomaton(width, height) {
    initialize();
}

void Rule30::initialize() {
    // Set the initial state for Rule 30 automaton
    grid[0][width / 2] = true;
}

void Rule30::update() {
    // Create a copy of the current grid to apply the rules without modifying the original
    std::vector<std::vector<bool>> newGrid = grid;

    // Apply Rule 30
    for (int i = 1; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int left = (j == 0) ? 0 : grid[i - 1][j - 1];
            int center = grid[i - 1][j];
            int right = (j == width - 1) ? 0 : grid[i - 1][j + 1];

            newGrid[i][j] = applyRule30(left, center, right);
        }
    }

    // Update the original grid with the new state
    grid = newGrid;
}

bool Rule30::applyRule30(bool left, bool center, bool right) const {
    return (left && !center && !right) ||
            (!left && center && right) ||
            (!left && center && !right) ||
            (!left && !center && right);
}
