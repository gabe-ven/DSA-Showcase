#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include "Model.h"

class Backtracking {
    Model* model;

public:
    Backtracking(Model* model);
    bool solve(int nodeIndex);
    bool isSolved();

    bool canPlaceBomb(const std::vector<std::pair<int, int>>& combination);
    void placeBomb(const std::vector<std::pair<int, int>>& combination);
    void reset(const std::vector<std::pair<int, int>>& combination);
};

#endif
