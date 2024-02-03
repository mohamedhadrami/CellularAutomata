/**
 * @file CellularAutomaton.h
 * @author Mohamed Hadrami
 * @brief 
 * @version 0.1
 * @date 2024-02-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

/**
 * @brief Base class for creating an automaton
 * 
 */
class CellularAutomaton {
public:
    /**
     * @brief Construct a new Cellular Automaton object
     * 
     * @param width grid width (default = 10)
     * @param height grid height (default = 10)
     */
    CellularAutomaton(int width = 10, int height = 10);

    /**
     * @brief Destroy the Cellular Automaton object
     * 
     */
    virtual ~CellularAutomaton() = default;

    /**
     * @brief Initializes with specific grid layout
     * 
     */
    virtual void initialize() = 0;

    /**
     * @brief Generates the next generation of automaton
     * 
     */
    virtual void update() = 0;

    /**
     * @brief Display current grid to monitor
     * 
     */
    void display() const;

    /**
     * @brief Sets FPS for display animation
     * 
     * @param fps 
     */
    void setFps(int fps);

    /**
     * @brief Runs the simulation indefinitely
     * 
     */
    void runSimulation();

protected:
    int width; // Specifies width of display grid
    int height; // Specifies height of display grid
    std::vector<std::vector<bool>> grid;
private:
    int fps; // Specifies frames per second to display animation
};
