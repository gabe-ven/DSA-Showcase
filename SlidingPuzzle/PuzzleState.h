#ifndef STATE_H
#define STATE_H

#include <vector>
#include <unordered_set>
#include <iostream>
#include "Constants.h"


class PuzzleState;
struct Hash;

class Node;

class PuzzleState {
    std::vector<int> board;
    int empty_tile;

public:
    PuzzleState();
    PuzzleState(const std::vector<int>& b);

    static std::vector<PuzzleState> a_star(const PuzzleState& start, const PuzzleState& goal);
    int manhattan_distance(const std::vector<int>& goal_board) const;
    static std::vector<PuzzleState> final_path(const std::unordered_map<PuzzleState, PuzzleState, Hash>& paths, PuzzleState current);

    std::vector<PuzzleState> getMoves() const;
    const std::vector<int>& getBoard() const { return board; }
    bool operator==(const PuzzleState& other) const { return board == other.board; }

};

struct Hash {
    size_t operator()(const PuzzleState& p) const {
        size_t hash = 0;
        for (int tile : p.getBoard()) {
            hash ^= std::hash<int>()(tile) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

#endif // STATE_H
