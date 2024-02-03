#include "GameOfLife.h"

GameOfLife::GameOfLife(int width, int height) : CellularAutomaton(width, height) {
    initialize();
}

void GameOfLife::initialize() {
    // Set the initial state of the grid for a glide pattern
    grid[1][1] = true;
    grid[2][2] = true;
    grid[2][3] = true;
    grid[3][1] = true;
    grid[3][2] = true;
}

void GameOfLife::update() {
    // Create a copy of the current grid to apply the rules without modifying the original
    std::vector<std::vector<bool>> newGrid = grid;

    // Iterate through each cell in the grid
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // Count the number of live neighbors for each cell
            int liveNeighbors = 0;
            for (int ni = i - 1; ni <= i + 1; ++ni) {
                for (int nj = j - 1; nj <= j + 1; ++nj) {
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width && !(ni == i && nj == j)) {
                        liveNeighbors += grid[ni][nj] ? 1 : 0;
                    }
                }
            }

            // Apply Conway's Game of Life rules
            if (grid[i][j]) {
                // Cell is currently alive
                newGrid[i][j] = (liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                // Cell is currently dead
                newGrid[i][j] = (liveNeighbors == 3);
            }
        }
    }

    // Update the original grid with the new state
    grid = newGrid;
}