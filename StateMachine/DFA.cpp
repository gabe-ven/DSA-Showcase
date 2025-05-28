#include "DFA.h"

DFA::DFA() {
    keywords = {
        "int", "double", "float", "return", "if", "else", "while", "for",
        "class", "struct", "break", "continue", "void", "static", "const",
        "bool", "char", "long", "short", "unsigned", "auto", "switch", "case",
        "do", "signed", "sizeof", "typedef","public", "private", "protected",
        "virtual", "override", "template","typename", "this", "new", "delete",
        "try", "catch", "throw"
    };
}

bool DFA::isValidIdentifier(const std::string& input) {
    setMessage("");
    State state = State::START;

    for (char c : input) {
        if (state == State::START) {
            if (isLetter(c) || isUnderscore(c)) {
                state = State::VALID;
            } else {
                state = State::INVALID;
                setMessage("ERROR: Identifier must start with a letter or underscore.");
                break;
            }
        }
        else if (state == State::VALID) {
            if (isLetter(c) || isDigit(c) || isUnderscore(c)) {
                continue;
            }
            else {
                state = State::INVALID;
                setMessage(std::string("ERROR: Invalid character '") + c + "' in identifier.");
                break;
            }
        }
    }
    if (state == State::VALID) {
        if (isReservedKeyword(input)) {
            setMessage("ERROR: Identifier cannot be a reserved keyword.");
            return false;
        }
        return true;
    }

    return false;
}


bool DFA::isReservedKeyword(const std::string& input) const {
    return keywords.find(input) != keywords.end();
}

bool DFA::isLetter(char c) const {
    return std::isalpha(static_cast<unsigned char>(c));
}

bool DFA::isDigit(char c) const {
    return std::isdigit(static_cast<unsigned char>(c));
}


bool DFA::isUnderscore(char c) const {
    return c == '_';
}

void DFA::setMessage(const std::string& msg) {
    message = msg;
}

std::string DFA::getMessage() const {
    return message;
}