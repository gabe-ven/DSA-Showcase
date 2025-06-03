
#ifndef PUZZLES_H
#define PUZZLES_H

#include <Malena/common.hpp>
#include <random>
#include "PuzzleState.h"
#include "Constants.h"

class Puzzle : public ml::Application {

    std::vector<int> start_board;
    std::vector<int> goal_board;

    PuzzleState start;
    PuzzleState goal;

    std::vector<PuzzleState> solutionPath;
    int step;

    sf::Clock clock;
    float delay = 0.5f;

    ml::Grid grid;
    sf::Font font;

    std::vector<ml::RectangleButton*> tiles;


public:
    Puzzle();
    void initialization() override;
    void registerEvents() override;
    void update();
    void createTiles(); // create 8 reusable tiles once
    void setupGrid(); // setup 3x3 grid
    void updateDisplay(const std::vector<int>& board);  // position tiles based on board state
};



#endif // PUZZLES_H
