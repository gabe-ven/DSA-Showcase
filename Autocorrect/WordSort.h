#ifndef WORDSORT_H
#define WORDSORT_H

#include "FileReader.h"
#include "Word.h"
#include "Heap.h"
#include <vector>
#include <string>
#include "SFML/Graphics/Font.hpp"

// uses FileReader to import data, then uses the data to compare with what the user types
// it has a heuristic function to determine a priority for each Word

class WordSort {
    std::vector<std::string> list;
    Heap<Word, std::greater<Word>> heap;
    sf::Font font;
public:
    WordSort(const std::string& filename, const sf::Font& font);
    double heuristic(const std::string& a, const std::string& b);
    void prioritize(const std::string& input);
    std::vector<Word> getTopWords(int num);
};

#endif // WORDSORT_H
