#include "BriansBrain.h"

BriansBrain::BriansBrain(int width, int height) :  CellularAutomaton(width, height), cellStates(height, std::vector<CellState>(width, DEAD)) {
    initialize();
}

void BriansBrain::initialize() {
    // Glider pattern
    grid[1][2] = true;
    grid[2][3] = true;
    grid[3][1] = true;
    grid[3][2] = true;
    grid[3][3] = true;

    // Update the cell states based on the initial grid state
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cellStates[i][j] = (grid[i][j] ? ALIVE : DEAD);
        }
    }
}

void BriansBrain::update() {
    std::vector<std::vector<CellState>> newCellStates(height, std::vector<CellState>(width, DEAD));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int aliveNeighbors = countAliveNeighbors(j, i);

            switch (cellStates[i][j]) {
                case DEAD:
                    newCellStates[i][j] = (aliveNeighbors == 2) ? ALIVE : DEAD;
                    break;
                case ALIVE:
                    newCellStates[i][j] = ALIVE;
                    break;
                case DYING:
                    newCellStates[i][j] = DEAD;
                    break;
            }

            if (cellStates[i][j] == ALIVE && newCellStates[i][j] == DEAD) {
                // Cell is newly alive and was dead before, mark as DYING
                newCellStates[i][j] = DYING;
            }
        }
    }

    // Update the original grid and cell states with the new state
    grid.clear();
    grid.resize(height, std::vector<bool>(width, false));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = (newCellStates[i][j] == ALIVE || newCellStates[i][j] == DYING);
        }
    }

    cellStates = std::move(newCellStates);
}


int BriansBrain::countAliveNeighbors(int x, int y) const {
    int count = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  // Skip the central cell

            int neighborX = (x + j + width) % width;
            int neighborY = (y + i + height) % height;

            if (cellStates[neighborY][neighborX] == ALIVE) {
                ++count;
            }
        }
    }

    return count;
}
