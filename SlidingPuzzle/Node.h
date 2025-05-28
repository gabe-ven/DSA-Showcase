#ifndef NODE_H
#define NODE_H
#include "PuzzleState.h"

class Node {
public:
    PuzzleState s;
    int g;
    int h;

    Node(PuzzleState s, int g, int h) : s(s), g(g), h(h) {}

    int f() const {
        return g + h;
    }
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        return a.f() > b.f();
    }
};

#endif // NODE_H
