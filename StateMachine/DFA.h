#ifndef DFA_H
#define DFA_H

#include <string>
#include <unordered_set>
#include <Malena/Managers/UIManager.h>


enum class State {
    START,
    VALID,
    INVALID
};

class DFA {
    std::unordered_set<std::string> keywords;
    std::string message;

public:
    DFA();
    bool isValidIdentifier(const std::string& input);
    bool isReservedKeyword(const std::string& input) const;
    bool isLetter(char c) const;
    bool isDigit(char c) const;
    bool isUnderscore(char c) const;
    void setMessage(const std::string& msg);
    std::string getMessage() const;
};

#endif //DFA_H
