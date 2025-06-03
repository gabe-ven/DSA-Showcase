#ifndef HOME_H
#define HOME_H

#include <Malena/common.hpp>
#include <Malena/Graphics/TextBox.h>
#include <Malena/Graphics/TextInput.h>
#include <Malena/Managers/UIManager.h>
#include "../Autocorrect/Autocorrect.h"
#include "../StateMachine/StateMachine.h"
#include "../Minesweeper/Minesweeper.h"
#include "../SlidingPuzzle/Puzzle.h"

class Home : public ml::Application {
private:
    ml::RectangleButton minesweeper, slidingPuzzle, stateMachine, autocorrect;
    ml::Text* titleText;
    sf::Font font;

public:
    Home();
    void initialization() override;
    void registerEvents() override;
};

#endif //HOME_H
