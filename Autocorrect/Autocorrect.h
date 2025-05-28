#ifndef AUTOCORRECT_H
#define AUTOCORRECT_H

#include <Malena/common.hpp>
#include <Malena/Graphics/TextBox.h>
#include <Malena/Graphics/TextInput.h>
#include <Malena/Managers/UIManager.h>

#include "WordSort.h"
#include "Word.h"

class Autocorrect : public ml::Application {
    ml::TextBox textBox;
    ml::TextInput textInput;
    ml::RectangleButton suggestionsBox;
    sf::Font font;
    WordSort* wordSort;
    std::vector<Word*> suggestions;

public:
    Autocorrect();
    void initialization() override;
    void registerEvents() override;
    void updateSuggestions(const std::string& input);
    std::function<void()> onTextChange;
};

#endif // AUTOCORRECT_H
