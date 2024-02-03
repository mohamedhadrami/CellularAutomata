/**
 * @file main.cpp
 * @author Mohamed Hadrami
 * @brief 
 * @version 0.1
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <memory>

#include "CellularAutomaton.h"
#include "GameOfLife.h"
#include "Rule30.h"
#include "LangtonsAnt.h"
#include "BriansBrain.h"


/**
 * @brief Displays usage instructions
 * 
 * @param programName 
 */
void displayUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " <automaton_type> [fps]" << std::endl;
}

/**
 * @brief Create a cellular automaton based on user input
 * 
 * @param automatonType 
 * @param width [int]
 * @param height [int]
 * @return std::unique_ptr<CellularAutomaton> 
 */
std::unique_ptr<CellularAutomaton> createAutomaton(const std::string& automatonType, int width, int height) {
    if (automatonType == "gameoflife") {
        return std::make_unique<GameOfLife>(width, height);
    } else if (automatonType == "rule30") {
        return std::make_unique<Rule30>(width, height);
    } else if (automatonType == "langtonsant") {
        return std::make_unique<LangtonsAnt>(width, height);
    } else if (automatonType == "briansbrain") {
        return std::make_unique<BriansBrain>(width, height);
    } else {
        return nullptr;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        displayUsage(argv[0]);
        return 1;
    }

    const std::string automatonType(argv[1]);
    const int width = 40;
    const int height = 20;
    int fps = 10;  // Default fps

    if (argc == 3) {
        try {
            fps = std::stoi(argv[2]);
        } catch (const std::exception& e) {
            std::cerr << "Invalid fps value. Using default fps (10)." << std::endl;
        }
    }

    // Create a unique_ptr to the base class (CellularAutomaton)
    auto automaton = createAutomaton(automatonType, width, height);

    if (!automaton) {
        std::cerr << "Invalid automaton type. Choose 'gameoflife', 'rule30', 'langtonsant', or 'briansbrain." << std::endl;
        return 1;
    }

    // Set frames per second
    automaton->setFps(fps);

    // Initialize and run the simulation
    automaton->initialize();
    automaton -> runSimulation();

    return 0;
}
