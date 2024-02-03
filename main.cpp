/**
 * @file main.cpp
 * @author Mohamed Hadrami
 * @brief A program for simulating various cellular automata.
 * @version 1.0
 * @date 2024-02-02
 * @copyright Copyright (c) 2024
 */

#include <iostream>
#include <string>
#include <memory>

#include "Automatons/CellularAutomaton.h"
#include "Automatons/GameOfLife.h"
#include "Automatons/Rule30.h"
#include "Automatons/LangtonsAnt.h"
#include "Automatons/BriansBrain.h"

/**
 * @brief Displays usage instructions
 * 
 * @param programName The name of the program.
 */
void displayUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " [options]" << std::endl;
    std::cerr << "Options:" << std::endl;
    std::cerr << "  -h, --help          Display this help message." << std::endl;
    std::cerr << "  -v, --version       Display the version of the program." << std::endl;
    std::cerr << "  -i, --info          Display additional information." << std::endl;
    std::cerr << "  -a, --automaton     Specify the automaton type. Available types:" << std::endl;
    std::cerr << "                       - gameoflife" << std::endl;
    std::cerr << "                       - rule30" << std::endl;
    std::cerr << "                       - langtonsant" << std::endl;
    std::cerr << "                       - briansbrain" << std::endl;
    std::cerr << "  -f, --fps           Specify the frames per second (default: 10)." << std::endl;
}

/**
 * @brief Displays version information
 */
void displayVersion() {
    std::cout << "CellularAutomata Version 1.0" << std::endl;
}

/**
 * @brief Displays additional information
 */
void displayInfo() {
    std::cout << "CellularAutomata is a program for simulating various cellular automata." << std::endl;
    // Add more information as needed
}
/**
 * @brief Create a cellular automaton based on user input
 * 
 * @param automatonType The type of cellular automaton to create.
 * @param width The width of the automaton grid.
 * @param height The height of the automaton grid.
 * @return std::unique_ptr<CellularAutomaton> A unique pointer to the created cellular automaton.
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

/**
 * @brief The main function of the program.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return int The exit status of the program.
 */
int main(int argc, char* argv[]) {
    // Default values
    const int defaultFps = 10;
    std::string automatonType;
    int fps = defaultFps;
    const int width = 40;
    const int height = 20;

    // Check the number of command-line arguments
    if (argc < 2 || argc > 3) {
        std::cerr << "Incorrect usage" << std::endl;
        displayUsage(argv[0]);
        return 1;
    }

    // Check for help, version, or info options
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (arg == "-h" || arg == "--help") {
            displayUsage(argv[0]);
            return 0;
        } else if (arg == "-v" || arg == "--version") {
            displayVersion();
            return 0;
        } else if (arg == "-i" || arg == "--info") {
            displayInfo();
            return 0;
        } else if ((arg == "-a" || arg == "--automaton") && i + 1 < argc) {
            automatonType = argv[i + 1];
            i++;  // Skip the next argument
        } else if ((arg == "-f" || arg == "--fps") && i + 1 < argc) {
            try {
                fps = std::stoi(argv[i + 1]);
                i++;  // Skip the next argument
            } catch (const std::exception& e) {
                std::cerr << "Invalid fps value. Using default fps (" << defaultFps << ")." << std::endl;
            }
        }
    }

    // Check if fps is provided as a command-line argument
    if (argc == 3) {
        try {
            fps = std::stoi(argv[2]);
        } catch (const std::exception& e) {
            std::cerr << "Invalid fps value. Using default fps (10)." << std::endl;
        }
    }

    // Create a unique_ptr to the base class (CellularAutomaton) based on user input
    auto automaton = createAutomaton(automatonType, width, height);

    // Check if the automaton type is valid
    if (!automaton) {
        std::cerr << "Invalid automaton type. Choose 'gameoflife', 'rule30', 'langtonsant', or 'briansbrain." << std::endl;
        return 1;
    }

    // Set frames per second
    automaton->setFps(fps);

    // Initialize and run the simulation
    automaton->initialize();
    automaton->runSimulation();

    return 0;
}
