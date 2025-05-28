//
// Created by Gabriel Venezia on 5/19/25.
//

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "DFA.h"
#include <Malena/common.hpp>
#include <Malena/Graphics/TextBox.h>
#include <Malena/Graphics/TextInput.h>


class StateMachine : public ml::Application {

    ml::TextBox textBox;
    ml::TextInput textInput;
    sf::Font font;
    ml::Typer typer;
    ml::Text message;
    DFA dfa;

public:
    StateMachine();
    void initialization() override;
    void registerEvents() override;
    std::function<void()> onTextChange;


};



#endif //STATEMACHINE_H
