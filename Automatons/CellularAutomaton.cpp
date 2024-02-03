#include "CellularAutomaton.h"

/**
 * @brief Construct a new CellularAutomaton::CellularAutomaton object
 * 
 * @param width 
 * @param height 
 */
CellularAutomaton::CellularAutomaton(int width, int height) : width(width), height(height), fps(10) {
    grid.resize(height, std::vector<bool>(width, false));
}

/**
 * @brief 
 * 
 */
void CellularAutomaton::display() const {
    // Clear the screen based on the platform
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << (grid[i][j] ? "X" : ".");
        }
        std::cout << std::endl;
    }

    // Add a delay to control the animation speed (adjust as needed)
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));  // Adjusted for fps
}

/**
 * @brief 
 * 
 * @param fps 
 */
void CellularAutomaton::setFps(int fps) {
    this->fps = fps;
}

/**
 * @brief 
 * 
 */
void CellularAutomaton::runSimulation() {
    while (true) {
        display();
        update();
    }
}
