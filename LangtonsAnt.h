#pragma once

#include "CellularAutomaton.h"

enum class AntDirection { UP, RIGHT, DOWN, LEFT };

class LangtonsAnt : public CellularAutomaton {
public:
    LangtonsAnt(int width, int height);

    void initialize() override;
    void update() override;

private:
    int antX;
    int antY;
    AntDirection antDirection;

    void moveAnt();
};
