#pragma once

#include "CellularAutomaton.h"

class GameOfLife : public CellularAutomaton {
public:
    GameOfLife(int width, int height);

    void initialize() override;
    void update() override;
};
