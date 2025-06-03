#include "PuzzleState.h"
#include "Node.h"

PuzzleState::PuzzleState() : board(N * N, 0), empty_tile(8) {}

PuzzleState::PuzzleState(const std::vector<int> &b) : board(b) {
    // set empty tile
    for (int i = 0; i < N*N; i++) {
        if (board[i] == 0) {
            empty_tile = i;
            break;
        }
    }
}

std::vector<PuzzleState> PuzzleState::aStar(const PuzzleState& start, const PuzzleState& goal) {
    // Node is what is stored in the queue
    // CompareNode is the struct that decides how to compare two Nodes
    // Node with smallest f value has highest priority
    std::priority_queue<Node, std::vector<Node>, CompareNode> unvisited;

    // closed set to keep track of visited puzzles
    // stores each Puzzle as a state
    // Hash is custom function so Puzzle objects can be stored and looked up in the set
    std::unordered_set<PuzzleState, Hash> visited;

    // maps for cost tracking and path reconstruction
    // Puzzle (key) - the current puzzle state you're tracking cost for
    // int (value) - current best known cost g from start node to puzzle state
    // Hash - custom function for Puzzle so it works as a key in the map
    std::unordered_map<PuzzleState, int, Hash> g;

    // Puzzle (key) - current puzzle state
    // Puzzle (value) - the previous puzzle state on current best path
    // Hash - custom function for Puzzle keys
    std::unordered_map<PuzzleState, PuzzleState, Hash> prev;

    g[start] = 0;
    int h = start.manhattanDistance(goal.board);
    unvisited.push(Node(start, 0, h)); // f = g + h

    while (!unvisited.empty()) {
        Node current = unvisited.top(); // neighbor with the lowest f
        unvisited.pop();

        PuzzleState currentState = current.s;
        // if we reached the goal, just return the path
        if (currentState == goal) {
            return finalPath(prev, currentState);
        }

        // visited node
        visited.insert(currentState);

        // generate all valid moves
        for (PuzzleState neighbor : currentState.getMoves()) {
            // calculate tentative cost from start to neighbor through current
            int tg = g[currentState] + 1; // each move is just 1

            // check if neighbor is already evaluated with a better score
            if (!g.count(neighbor) || tg < g[neighbor]) {
                // this path to neighbor is better than any previous one
                g[neighbor] = tg;  // update cost to reach neighbor
                int h = neighbor.manhattanDistance(goal.board);  // heuristic estimate to goal

                prev[neighbor] = currentState;  // remember path

                // push neighbor to open_set (priority queue)
                unvisited.push(Node(neighbor, tg, h));
            }
        }
    }
    return {};
}

int PuzzleState::manhattanDistance(const std::vector<int>& board) const {
    int dist = 0;

    for (int i = 0; i < N * N; i++) {
        int tile = board[i];
        if (tile == 0) {
            continue;
        }

        int curr_row = i / N;
        int curr_col = i % N;
        int goal_row = (tile - 1) / N;
        int goal_col = (tile - 1) % N;

        dist += abs(curr_row - goal_row) + abs(curr_col - goal_col);
    }

    return dist;
}

std::vector<PuzzleState> PuzzleState::finalPath(const std::unordered_map<PuzzleState, PuzzleState, Hash>& paths, PuzzleState current) {
    std::vector<PuzzleState> total_path;
    total_path.push_back(current);

    while (paths.find(current) != paths.end()) {
        current = paths.at(current);
        total_path.push_back(current);
    }

    std::reverse(total_path.begin(), total_path.end());
    return total_path;
}

std::vector<PuzzleState> PuzzleState::getMoves() const {
    const std::vector<std::pair<int,int>> directions = {
        {-1, 0}, // up
        {1, 0},  // down
        {0, -1}, // left
        {0, 1}   // right
    };

    std::vector<PuzzleState> neighbors;
    int row = empty_tile / N;
    int col = empty_tile % N;

    for (const auto& d : directions) {
        int r = row + d.first;
        int c = col + d.second;

        // check if its in bounds
        if (r >= 0 && r < N && c >= 0 && c < N) {
            int new_index = r * N + c;
            std::vector<int> new_board = board;
            std::swap(new_board[empty_tile], new_board[new_index]);
            neighbors.push_back(PuzzleState(new_board)); // creates a new Puzzle with new board
        }
    }
    return neighbors;
}
