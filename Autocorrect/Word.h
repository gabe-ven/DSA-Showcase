#ifndef WORD_H
#define WORD_H

#include <Malena/common.hpp>

// inherits ml::Text. It adds a new parameter, priority so that it can be added to my heap
class Word : public ml::Text {
    double priority;

public:
    Word(const std::string& str, const sf::Font& font, double p = 0)
    : Text(font), priority(p) {
        setString(str);
    }
    bool operator>(const Word& other) const { return priority > other.priority; }
};

#endif // WORD_H
