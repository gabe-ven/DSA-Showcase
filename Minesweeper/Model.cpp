#include "Model.h"
#include "Node.h"
#include <cstdlib>
#include <ctime>
#include <vector>

// all possible locations
std::vector<std::pair<int, int>> DIRECTIONS = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

Model::Model(int rows, int cols, int numBombs)
    : board(rows, std::vector(cols, '-')) {

    std::srand(std::time(nullptr));
    int placed = 0;

    // keep placing bombs randomly
    while (placed < numBombs) {
        int x = std::rand() % rows;
        int y = std::rand() % cols;

        if (board[x][y] == '-') {
            bombPositions.push_back({x, y});
            placed++;
        }
    }
    calculateNums();
    generateNodes();
}

void Model::calculateNums() {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // skip over bomb
            if (isBomb(i, j)) {
            continue;
        }
            int count = 0;
            // go through all the directions
            for (const auto& direction : DIRECTIONS) {
                int k = i + direction.first;
                int l = j + direction.second;
                // see if the number is adjacent to a bomb
                if (k >= 0 && k  < rows && l >= 0 && l < cols && isBomb(k , l))
                    count++;
            }
            if (count) {
                board[i][j] = '0' + count;  // set the number of adjacent bombs
            } else {
                board[i][j] = '-';  // set empty if no adjacent
            }
        }
    }
}

void Model::generateNodes() {
    nodes.clear();  // clear existing nodes

    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char val = board[i][j];

            if (val >= '1' && val <= '8') {  // check if its numbered
                std::vector<std::pair<int, int>> neighbors = getNeighbors(i, j);  // get neighbors
                nodes.push_back(new Node(i, j, val - '0', neighbors));  // create node with the neighbors
            }
        }
    }
}

// go through directions and get all adjacent neighbors
std::vector<std::pair<int, int>> Model::getNeighbors(int x, int y) const {
    std::vector<std::pair<int, int>> neighbors;
    int rows = board.size(), cols = board[0].size();
    for (const auto& direction : DIRECTIONS) {
        int i = x + direction.first;
        int j = y + direction.second;
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            neighbors.push_back({i, j});
        }
    }
    return neighbors;
}

// at the very end show all the flags as bombs
void Model::convertToBombs() {
    for (const auto& bomb : bombPositions) {
        if (board[bomb.first][bomb.second] == 'F') {
            board[bomb.first][bomb.second] = 'X';
        }
    }
}

// check if its a bomb
bool Model::isBomb(int x, int y) const {
    for (const auto& bomb : bombPositions) {
        if (bomb.first == x && bomb.second == y) {
            return true;
        }
    }
    return false;
}

