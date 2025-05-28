#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
    int x, y;
    int num;
    std::vector<std::vector<std::pair<int, int>>> validCombinations;

public:
    Node(int x, int y, int num, const std::vector<std::pair<int, int>>& neighbors);

    int getX() const { return x; }
    int getY() const { return y; }
    int getNum() const { return num; }

    void generateCombinations(const std::vector<std::pair<int, int>>& neighbors, int start, int n, std::vector<std::pair<int, int>>& combination);
    std::vector<std::vector<std::pair<int, int>>> getValidCombinations() const;

};

#endif // NODE_H
