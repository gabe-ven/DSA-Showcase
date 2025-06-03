#include "Autocorrect.h"
#include <SFML/Graphics.hpp>
#include "Word.h"

Autocorrect::Autocorrect()
    : Application(sf::VideoMode({720, 420}, 32), "Autocorrect") {
    setBackground(sf::Color(134, 210, 147));
    ml::FontManager::loadFontFromFile("roboto", "../fonts/Roboto-VariableFont_wdth,wght.ttf");
    font = ml::FontManager::getFont("roboto");
    wordSort = new WordSort("5000-baby-girl-names.txt", font);
}

void Autocorrect::initialization() {
    textBox.setSize({500, 50});
    textBox.setPosition({110, 50});
    textBox.setFillColor(sf::Color(34, 34, 34));
    textBox.setOutlineThickness(2.0f);
    textBox.setOutlineColor(sf::Color(134, 210, 147));

    textInput.setPosition({110, 50});
    textInput.setFont(font);
    textInput.setCharacterSize(35);
    textInput.setTextColor(sf::Color::White);

    suggestionsBox.setSize({500, 500});
    suggestionsBox.setPosition({110, 105});
    suggestionsBox.setFillColor(sf::Color(100, 157, 110));

    addComponent(textBox);
    addComponent(textInput);
    addComponent(suggestionsBox);
}

void Autocorrect::registerEvents() {
    textBox.onFocus([this]() {
        textBox.enableState(ml::Stateful::FOCUSED);
        textInput.enableState(ml::Stateful::FOCUSED);
        textInput.enableState(ml::Stateful::ENABLED);
        textInput.enableState(ml::Stateful::BLINKING);
        textBox.setOutlineColor(sf::Color(98, 86, 202));
        std::cout << "textbox focused" << std::endl;
    });

    textBox.onBlur([this]() {
        textBox.disableState(ml::Stateful::FOCUSED);
        textInput.disableState(ml::Stateful::FOCUSED);
        textInput.disableState(ml::Stateful::ENABLED);
        textInput.disableState(ml::Stateful::BLINKING);
        textBox.setOutlineColor(sf::Color(134, 210, 147));
        std::cout << "textbox lost focus" << std::endl;
    });

    textBox.onHover([this]() {
        textBox.setFillColor(sf::Color(50, 50, 50));
    });

    textBox.onUnhover([this]() {
        textBox.setFillColor(sf::Color(34, 34, 34));
    });

    textInput.onTextChange = [this]() {
        const std::string input = textInput.getText();
        updateSuggestions(input);
    };
}

void Autocorrect::updateSuggestions(const std::string& input) {
    // for empty input
    if (input.empty()) {
        // clear existing suggestions
        for (Word* w : suggestions) {
            w->setString("");
        }
        return;
    }
    // priortize the input
    wordSort->prioritize(input);
    // how many words to appear
    auto topWords = wordSort->getTopWords(10);

    float y = suggestionsBox.getPosition().y + 5;
    float x = 110;

    // loop through all the top words
    for (int i = 0; i < topWords.size(); i++) {
        if (i < suggestions.size()) {
            suggestions[i]->setString(topWords[i].getString());
            suggestions[i]->setPosition({x, y});
        } else {
            // create new word based off the current top word
            Word* w = new Word(topWords[i].getString(), font);
            w->setCharacterSize(30);
            w->setFont(font);
            w->setFillColor(sf::Color::White);
            w->setPosition({x, y});
            addComponent(*w);
            suggestions.push_back(w);
        }
        // update spacing
        y += suggestions[i]->getLocalBounds().size.y + 5;
    }

    // clear old suggestions
    for (int i = topWords.size(); i < suggestions.size(); i++) {
        suggestions[i]->setString("");
    }
}

