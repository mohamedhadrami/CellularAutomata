#pragma once

#include "CellularAutomaton.h"

class Rule30 : public CellularAutomaton {
public:
    Rule30(int width, int height);

    void initialize() override;
    void update() override;

private:
    bool applyRule30(bool left, bool center, bool right) const;
};
