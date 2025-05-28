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

std::vector<PuzzleState> PuzzleState::a_star(const PuzzleState& start, const PuzzleState& goal) {
    // Node is what is stored in the queue
    // CompareNode is the struct that decides how to compare two Nodes
    // Node with smallest f value has highest priority
    std::priority_queue<Node, std::vector<Node>, CompareNode> to_explore;

    // closed set to keep track of visited puzzles
    // stores each Puzzle as a state
    // Hash is custom function so Puzzle objects can be stored and looked up in the set
    std::unordered_set<PuzzleState, Hash> explored;

    // maps for cost tracking and path reconstruction
    // Puzzle (key) - the current puzzle state you're tracking cost for
    // int (value) - current best known cost g from start node to puzzle state
    // Hash - custom function for Puzzle so it works as a key in the map
    std::unordered_map<PuzzleState, int, Hash> g;

    // Puzzle (key) - current puzzle state
    // Puzzle (value) - the previous puzzle state on current best path
    // Hash - custom function for Puzzle keys
    std::unordered_map<PuzzleState, PuzzleState, Hash> paths;

    g[start] = 0;
    int h = start.manhattan_distance(goal.board);
    to_explore.push(Node(start, 0, h)); // this is f

    while (!to_explore.empty()) {
        Node current = to_explore.top(); // neighbor with the lowest f
        to_explore.pop();

        PuzzleState currentState = current.s;
        // if we reached the goal, just return the path
        if (currentState == goal) {
            return final_path(paths, currentState);
        }

        // explored node
        explored.insert(currentState);

        // generate all valid moves
        for (PuzzleState neighbor : currentState.getMoves()) {
            // calculate tentative cost from start to neighbor through current
            int tentative_g = g[currentState] + 1; // each move is just 1

            // check if neighbor is already evaluated with a better score
            if (g.find(neighbor) == g.end() || tentative_g < g[neighbor]) {
                // this path to neighbor is better than any previous one
                g[neighbor] = tentative_g;  // update cost to reach neighbor
                int h = neighbor.manhattan_distance(goal.board);  // heuristic estimate to goal

                paths[neighbor] = currentState;  // remember path

                // push neighbor to open_set (priority queue)
                to_explore.push(Node(neighbor, tentative_g, h));
            }
        }
    }
    return {};
}

int PuzzleState::manhattan_distance(const std::vector<int>& goal_board) const {
    int distance = 0;

    std::vector<std::pair<int, int>> goal_positions(N * N);

    // precompute goal positions
    for (int i = 0; i < N * N; i++) {
        goal_positions[goal_board[i]] = {i / N, i % N};
    }

    // loop through board
    for (int i = 0; i < N * N; i++) {
        int tile = board[i];
        // skip empty tile
        if (tile == 0) {
            continue;
        }

        // add how far this tile is from the goal to total distance
        // do this for ALL board states
        distance += abs((i % N) - (goal_positions[tile].second)) + abs((i / N) - (goal_positions[tile].first));
    }

    return distance;
}

std::vector<PuzzleState> PuzzleState::final_path(const std::unordered_map<PuzzleState, PuzzleState, Hash>& paths, PuzzleState current) {
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
