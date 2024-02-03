#pragma once

#include "CellularAutomaton.h"

class BriansBrain : public CellularAutomaton {
public:
    BriansBrain(int width, int height);

    void initialize() override;
    void update() override;

private:
    enum CellState { DEAD, ALIVE, DYING };
    std::vector<std::vector<CellState>> cellStates;
    int countAliveNeighbors(int x, int y) const;
};
