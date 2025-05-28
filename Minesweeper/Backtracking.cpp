#include "Backtracking.h"

Backtracking::Backtracking(Model* model)
    : model(model) {}

bool Backtracking::solve(int index) {
    if (index == model->getNodes().size()) {
        if (isSolved()) { // check if all nodes have correct bomb count
            model->convertToBombs(); // convert all flags (F) into bombs (X)
            model->saveStep(); // save board state
            return true; // board is solved
        }
        return false; // continue searching
    }
    Node* node = model->getNode(index);
    model->setCurrentNodePosition(node->getX(), node->getY()); // set current position to the node
    model->saveStep(); // save board state

    for (const auto& combination : node->getValidCombinations()) {
        if (canPlaceBomb(combination)) { // check if bombs can be placed without breaking the boards rules
            placeBomb(combination); // place bombs for this combination
            if (solve(index + 1)) { // recursively solve the next node
                return true; // if solving the next node works, return true
            }
            reset(combination); // backtrack: remove placed bombs and reset
        }
    }
    return false; // no valid bomb placement was found for this node
}

bool Backtracking::isSolved() {
    for (Node* node : model->getNodes()) { // for every node in the board
        int count = 0;
        // get all neighboring cell cords around the current node
        auto neighbors = model->getNeighbors(node->getX(), node->getY());

        // count how many of the neighboring cells are flagged as bombs
        for (const auto& coord : neighbors) {
            if (model->getBoardValue(coord.first, coord.second) == 'F')
                count++;
        }
        // if the count doesnt match the nodes number then its not solved correctly
        if (count != node->getNum())
            return false;
    }
    return true;
}

bool Backtracking::canPlaceBomb(const std::vector<std::pair<int, int>>& combination) {
    // check valid placement locations
    for (const auto& coord : combination) {
        char val = model->getBoardValue(coord.first, coord.second);
        // if tile is not empty ('-') or a flag ('F') then its invalid
        if (val != '-' && val != 'F') {
            return false;
        }
    }
    for (Node* node : model->getNodes()) {
        int count = 0;
        // get all neighbors of the current node
        auto neighbors = model->getNeighbors(node->getX(), node->getY());

        // count the bombs around the node
        for (const auto& n : neighbors) {
            // if neighboring tile is flagged as a bomb or part of the current combination, count it as bomb
            if (model->getBoardValue(n.first, n.second) == 'F') {
                count++;
            }
        }
        // if bomb count is more than number, its invalid
        if (count > node->getNum()) {
            return false;
        }
    }
    return true;
}

void Backtracking::placeBomb(const std::vector<std::pair<int, int>>& combination) {
    for (const auto& coord : combination) {
        if (model->getBoardValue(coord.first, coord.second) == '-') { // if empty
            model->setBoardValue(coord.first, coord.second, 'F'); // place flag
        }
    }
}

void Backtracking::reset(const std::vector<std::pair<int, int>>& combination) {
    for (const auto& coord : combination) {
        if (model->getBoardValue(coord.first, coord.second) == 'F') { // if flag
            model->setBoardValue(coord.first, coord.second, '-'); // place empty
        }
    }
}
