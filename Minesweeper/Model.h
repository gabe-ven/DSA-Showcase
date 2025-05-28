#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include "Node.h"

class Model {
    std::vector<std::vector<char>> board;
    std::vector<Node*> nodes;
    std::vector<std::vector<std::vector<char>>> steps;
    std::vector<std::pair<int, int>> nodePositions;
    std::pair<int, int> currentNodePosition;
    std::vector<std::pair<int, int>> bombPositions;

public:
    // constructor
    Model(int rows, int cols, int numBombs);

    // board stuff
    std::vector<std::vector<char>>& getBoard() { return board; }
    char getBoardValue(int x, int y) const { return board[x][y]; }
    void setBoardValue(int x, int y, char val) { board[x][y] = val; }

    // node stuff
    std::vector<Node*>& getNodes() { return nodes; }
    Node* getNode(int i) const { return nodes[i]; }
    const std::vector<std::pair<int, int>>& getNodePositions() const { return nodePositions; }

    // step saving
    void saveStep() { steps.push_back(board), nodePositions.push_back(currentNodePosition); }
    const std::vector<std::vector<std::vector<char>>>& getSteps() const { return steps; }

    // current node position
    void setCurrentNodePosition(int x, int y) { currentNodePosition = {x, y}; }
    std::pair<int, int> getCurrentNodePosition() const { return currentNodePosition; }


    // bomb stuff
    void convertToBombs();
    bool isBomb(int x, int y) const;
    std::vector<std::pair<int, int>> getBombPositions() const { return bombPositions; }

    // game logic
    void calculateNums();
    void generateNodes();
    std::vector<std::pair<int, int>> getNeighbors(int x, int y) const;

};

#endif
