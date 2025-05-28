#include "Minesweeper.h"

Minesweeper::Minesweeper(int rows, int cols, int bombs)
    : Application(600, 600, 32, "Minesweeper Backtracker"),
      model(nullptr), backtracking(nullptr), rects(0), delay(0.05f), currentStep(0)
{
    this->rows = rows;
    this->cols = cols;
    this->bombs = bombs;
}

void Minesweeper::initialization() {
    // load image and slice
    texture.loadFromFile("assets/minesweep_cut.png");
    rects = ml::TextureSlicer::getImageRects(texture, 11, 12);

    // model and solver
    model = new Model(rows, cols, bombs);
    backtracking = new Backtracking(model);
    backtracking->solve(0);
    backtrackSteps = model->getSteps();

    // prepare and show the initial board
    createTiles(backtrackSteps[0]); // initialize tiles once
    refreshBoard(backtrackSteps[0]); // set initial tile textures

    // update every time
    onUpdate([this] {
        update();
    });
}

// animate steps
void Minesweeper::update() {
    if (currentStep >= backtrackSteps.size()) {
        return;
    }

    if (clock.getElapsedTime().asSeconds() >= delay) {
        refreshBoard(backtrackSteps[currentStep]);
        currentStep++;
        clock.restart();
    }
}


// create initial tiles
void Minesweeper::createTiles(const std::vector<std::vector<char>>& board) {
    int rows = board.size();
    int cols = board[0].size();

    float tileSize = std::min(ml::WindowManager::getWindow().getSize().x / float(cols),
    ml::WindowManager::getWindow().getSize().y / float(rows));

    tiles.resize(rows * cols);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int index = row * cols + col;
            ml::Rectangle& rect = tiles[index];

            rect.setSize({tileSize, tileSize});
            rect.setPosition({col * tileSize, row * tileSize});
            rect.setTexture(&texture);

            addComponent(rect);
        }
    }
}

// Updates tile textures and colors based on current step
void Minesweeper::refreshBoard(const std::vector<std::vector<char>>& board)
{
    int rows = board.size();
    int cols = board[0].size();

    std::pair currentPos = {0,0};
    if (currentStep < model->getNodePositions().size()) {
        currentPos = model->getNodePositions()[currentStep];
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int index = row * cols + col;
            ml::Rectangle& rect = tiles[index];

            char cell = board[row][col];
            sf::IntRect intRect;

            if (cell == '-') {
                intRect = rects.getIntRect(0, 0); // empty
            } else if (cell == 'F') {
                intRect = rects.getIntRect(0, 2); // flag
            } else if (cell >= '1' && cell <= '8') {
                intRect = rects.getIntRect(1, cell - '1'); // numbers
            } else if (cell == 'X') {
                intRect = rects.getIntRect(0, 5); // bomb
            }

            rect.setTextureRect(intRect);

            // highlight current node
            if (currentPos.first == row && currentPos.second == col) {
                rect.setFillColor(sf::Color::Yellow);
            } else {
                rect.setFillColor(sf::Color::White); // reset color
            }
        }
    }
}

void Minesweeper::registerEvents()
{
}
