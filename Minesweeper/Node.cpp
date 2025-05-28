#include "Node.h"


Node::Node(int x, int y, int num, const std::vector<std::pair<int, int>>& neighbors): x(x), y(y), num(num) {
    std::vector<std::pair<int, int>> temp;
    generateCombinations(neighbors, 0, num, temp);
}

void Node::generateCombinations(const std::vector<std::pair<int, int>>& neighbors, int start, int n, std::vector<std::pair<int, int>>& combination) {
    if (combination.size() == n) { // if the combination has the desired amount of bombs
        validCombinations.push_back(combination); // add this combination to the list of valid combinations
        return;
    }

    for (int i = start; i < neighbors.size(); i++) {
        combination.push_back(neighbors[i]); // choose this position
        generateCombinations(neighbors, i + 1, n, combination); // recursively find the next positions
        combination.pop_back(); // backtrack: un-choose the position
    }
}

std::vector<std::vector<std::pair<int, int>>> Node::getValidCombinations() const {
    return validCombinations;
}
