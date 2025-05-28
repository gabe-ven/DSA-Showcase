//
// Created by Gabriel Venezia on 5/19/25.
//

#include "StateMachine.h"

StateMachine::StateMachine() : Application(sf::VideoMode({720, 420}, 32), "StateMachine", *this) {
    setBackground(sf::Color(104, 149, 210));
    font = ml::FontManager::getFont(ml::FontManager::ARIAL);
}

void StateMachine::initialization() {
    textBox.setSize({500, 50});
    textBox.setPosition({110, 50});
    textBox.setFillColor(sf::Color(34, 34, 34));
    textBox.setOutlineThickness(2.0f);
    textBox.setOutlineColor(sf::Color(104, 149, 210));

    textInput.setTextColor(sf::Color::Black);
    textInput.setPosition({110, 50});
    textInput.setFont(font);
    textInput.setCharacterSize(35);

    message.setFont(font);
    message.setString("");


    addComponent(textBox);
    addComponent(textInput);
    addComponent(message);

}

void StateMachine::registerEvents() {
    textBox.onFocus([this]() {
        textBox.enableState(ml::Stateful::FOCUSED);
        textInput.enableState(ml::Stateful::ENABLED);
        textInput.enableState(ml::Stateful::BLINKING);
        textBox.setOutlineColor(sf::Color(243, 185, 95));
        std::cout << "textbox focused" << std::endl;
    });

    textBox.onBlur([this]() {
        textBox.disableState(ml::Stateful::FOCUSED);
        textInput.disableState(ml::Stateful::ENABLED);
        textInput.disableState(ml::Stateful::BLINKING);
        textBox.setOutlineColor(sf::Color(104, 149, 210));
        std::cout << "textbox lost focus" << std::endl;
    });

    textBox.onHover([this]() {
        textBox.setFillColor(sf::Color(50, 50, 50));
    });

    textBox.onUnhover([this]() {
        textBox.setFillColor(sf::Color(34, 34, 34));
    });

    textInput.onTextChange = [this]() {
        std::string input = textInput.getText();
        if (input.empty()) {
            textInput.setTextColor(sf::Color::Black);
            message.setString("");
        }
        else if (dfa.isValidIdentifier(input)) {
            textInput.setTextColor(sf::Color::Green);
            message.setCharacterSize(40);
            message.setString("VALID");
            message.setFillColor(sf::Color::Green);
        }
        else {
            textInput.setTextColor(sf::Color::Red);
            message.setCharacterSize(25);
            message.setString(dfa.getMessage());
            message.setFillColor(sf::Color::Red);
        }
        sf::FloatRect bounds = message.getLocalBounds();
        message.setOrigin({bounds.position.x + bounds.size.x / 2.0f, bounds.position.y + bounds.size.y / 2.0f});

        sf::FloatRect boxBounds = static_cast<sf::RectangleShape&>(textBox).getGlobalBounds();
        message.setPosition({boxBounds.position.x + boxBounds.size.x / 2.0f,
                            boxBounds.position.y + boxBounds.size.y + 20});
    };


}
