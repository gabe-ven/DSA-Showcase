//
// Created by Gabriel Venezia on 5/10/25.
//

#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

// reads data from a file, and stores it in a vector
class FileReader {
    std::vector<std::string> words;
public:
    FileReader(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }

        std::string word;
        while (file >> word) {
            words.push_back(word);
        }
    }

    // return vector of words
    const std::vector<std::string>& getWords() const {
        return words;
    }
};

#endif //FILEREADER_H
