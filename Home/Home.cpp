//
// Created by Gabriel Venezia on 5/30/25.
//

#include "Home.h"

Home::Home() : Application(800, 600, 32, "DSA Projects") {
    setBackground(sf::Color(84, 68, 123));
    ml::FontManager::loadFontFromFile("rubik", "../fonts/Rubik-Bold.ttf");
    font = ml::FontManager::getFont("rubik");
}

void Home::initialization() {
    const float BUTTON_WIDTH = 220;
    const float BUTTON_HEIGHT = 50;
    const float BUTTON_SPACING = 20;
    const float START_Y = 200;

    titleText = new ml::Text(font);
    titleText->setString("projects");
    titleText->setCharacterSize(48);
    titleText->setFillColor(sf::Color::White);

    sf::FloatRect bounds = titleText->getLocalBounds();
    titleText->setOrigin({bounds.size.x / 2, bounds.size.y / 2});
    titleText->setPosition({400, 100});

    // Minesweeper button
    minesweeper.setSize({BUTTON_WIDTH, BUTTON_HEIGHT});
    minesweeper.setPosition({400 - BUTTON_WIDTH/2, START_Y});
    minesweeper.setFillColor(sf::Color(238, 90, 90));
    minesweeper.setString("Minesweeper");
    minesweeper.setFont(font);
    minesweeper.setCharacterSize(24);
    minesweeper.setPosition({400 - BUTTON_WIDTH/2, START_Y + BUTTON_HEIGHT/2});

    // Sliding Puzzle button
    slidingPuzzle.setSize({BUTTON_WIDTH, BUTTON_HEIGHT});
    slidingPuzzle.setPosition({400 - BUTTON_WIDTH/2, START_Y + BUTTON_HEIGHT + BUTTON_SPACING});
    slidingPuzzle.setFillColor(sf::Color(12, 156, 238));
    slidingPuzzle.setString("Sliding Puzzle");
    slidingPuzzle.setFont(font);
    slidingPuzzle.setCharacterSize(24);
    slidingPuzzle.setPosition({400 - BUTTON_WIDTH/2, START_Y + BUTTON_HEIGHT + BUTTON_SPACING + BUTTON_HEIGHT/2});

    // State Machine button
    stateMachine.setSize({BUTTON_WIDTH, BUTTON_HEIGHT});
    stateMachine.setPosition({400 - BUTTON_WIDTH/2, START_Y + 2*(BUTTON_HEIGHT + BUTTON_SPACING)});
    stateMachine.setFillColor(sf::Color(255, 217, 68));
    stateMachine.setString("State Machine");
    stateMachine.setFont(font);
    stateMachine.setCharacterSize(24);
    stateMachine.setPosition({400 - BUTTON_WIDTH/2, START_Y + 2*(BUTTON_HEIGHT + BUTTON_SPACING) + BUTTON_HEIGHT/2});

    // Autocorrect button
    autocorrect.setSize({BUTTON_WIDTH, BUTTON_HEIGHT});
    autocorrect.setPosition({400 - BUTTON_WIDTH/2, START_Y + 3*(BUTTON_HEIGHT + BUTTON_SPACING)});
    autocorrect.setFillColor(sf::Color(148, 221, 77));
    autocorrect.setString("Autocorrect");
    autocorrect.setFont(font);
    autocorrect.setCharacterSize(24);
    autocorrect.setPosition({400 - BUTTON_WIDTH/2, START_Y + 3*(BUTTON_HEIGHT + BUTTON_SPACING) + BUTTON_HEIGHT/2});

    addComponent(*titleText);
    addComponent(minesweeper);
    addComponent(slidingPuzzle);
    addComponent(stateMachine);
    addComponent(autocorrect);
}

void Home::registerEvents() {
    minesweeper.onClick([this]() {
        Minesweeper minesweeper(9, 9, 10);
        minesweeper.run();
    });

    slidingPuzzle.onClick([this]() {
        Puzzle puzzle;
        puzzle.run();
    });

    stateMachine.onClick([this]() {
        StateMachine stateMachine;
        stateMachine.run();
    });

    autocorrect.onClick([this]() {
        Autocorrect autocorrect;
        autocorrect.run();
    });
}
