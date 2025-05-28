#include "Puzzle.h"

Puzzle::Puzzle() : Application(sf::VideoMode({470, 470}, 32), "Sliding Puzzle", *this) {
    setBackground(sf::Color(70, 9, 184));
    ml::FontManager::loadFontFromFile("kanit", "../fonts/Kanit-SemiBold.ttf");
    font = ml::FontManager::getFont("kanit");
}

void Puzzle::initialization() {
    goal_board = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 0
    };
    std::vector<std::vector<int>> start_boards = {
        {1, 2, 3, 4, 5, 7, 8, 6, 0},
        {1, 2, 3, 5, 0, 6, 4, 7, 8},
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {6, 4, 7, 8, 5, 0, 3, 2, 1},
        {8, 6, 7, 2, 5, 4, 3, 0, 1},
        {1, 8, 2, 0, 4, 3, 7, 6, 5},
        {1, 2, 3, 4, 0, 6, 7, 5, 8},
        {1, 3, 6, 5, 0, 2, 4, 7, 8},
        {8, 0, 6, 5, 4, 7, 2, 3, 1},
        {4, 1, 2, 5, 0, 3, 7, 8, 6},
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, start_boards.size() - 1);

    int rand = dis(gen);
    start_board = start_boards[rand];

    start = PuzzleState(start_board);
    goal = PuzzleState(goal_board);

    createTiles();
    setupGrid();
    updateDisplay(start_board);

    solutionPath = PuzzleState::a_star(start, goal);
    step = 0;
    clock.restart();

    onUpdate([this] {
        update();
    });
}

void Puzzle::createTiles() {
    tiles.clear();
    texts.clear();

    // create exactly 8 tiles (numbers 1-8) once
    for (int value = 1; value <= 8; value++) {
        // create tile
        auto* tile = new ml::Rectangle();
        tile->setSize({TILE_SIZE, TILE_SIZE});

        // set color based on value
        if (value >= 1 && value <= 3)
            tile->setFillColor(sf::Color(255, 214, 58));
        else if (value >= 4 && value <= 6)
            tile->setFillColor(sf::Color(255, 169, 85));
        else if (value >= 7 && value <= 8)
            tile->setFillColor(sf::Color(247, 90, 90));


        tiles.push_back(tile);

        // create text
        auto* text = new ml::Text(font);
        text->setString(std::to_string(value));
        text->setCharacterSize(TEXT_SIZE);
        text->setFillColor(sf::Color::White);

        // position text in center
        sf::FloatRect bounds = text->getLocalBounds();
        text->setOrigin({bounds.position.x + bounds.size.x / 2.f,
                         bounds.position.y + bounds.size.y / 2.f});
        texts.push_back(text);

        // add to application
        addComponent(*tile);
        addComponent(*text);
    }
}

void Puzzle::setupGrid() {
    grid = ml::Grid({N, N});
    grid.setSpacing(SPACING);
    grid.setPosition({GRID_POSITION, GRID_POSITION});

    // create placeholders for where the tiles will go
    for (int i = 0; i < N * N; i++) {
        auto* placeholder = new ml::Rectangle();
        placeholder->setSize({TILE_SIZE, TILE_SIZE});
        placeholder->setFillColor(sf::Color::Transparent);
        grid.addComponent(*placeholder);
    }

    grid.addToApplication(*this);
}


void Puzzle::updateDisplay(const std::vector<int>& board) {
    for (int i = 0; i < N * N; i++) {
        int value = board[i];
        if (value == 0)
            continue; // skip empty space

        // calculate position for this grid spot
        int row = i / N;
        int col = i % N;
        float x = GRID_POSITION + col * (TILE_SIZE + SPACING);
        float y = GRID_POSITION + row * (TILE_SIZE + SPACING);

        int index = value - 1;
        tiles[index]->setPosition({x, y});
        texts[index]->setPosition({x + TILE_SIZE / 2, y + TILE_SIZE / 2 - SPACING});
    }
}

void Puzzle::update() {
    if (step >= solutionPath.size()) {
        return;
    }
    if (clock.getElapsedTime().asSeconds() >= delay) {
        updateDisplay(solutionPath[step].getBoard());
        step++;
        clock.restart();
    }
}

void Puzzle::registerEvents() {

}

