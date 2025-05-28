#include "WordSort.h"
#include <cctype>
#include <algorithm>
#include <cmath>

WordSort::WordSort(const std::string& filename, const sf::Font& font) : font(font) {
    FileReader reader(filename);
    list = reader.getWords();
}

double WordSort::heuristic(const std::string& a, const std::string& b) {
    if (a == b) {
        return 1.0;
    }

    std::string s1 = a;
    std::string s2 = b;
    for (char& c : s1) {
        c = std::tolower(c);
    }
    for (char& c : s2) {
        c = std::tolower(c);
    }

    double score = 0.0;
    int len1 = s1.size();
    int len2 = s2.size();
    int maxLen = std::max(len1, len2);
    int minLen = std::min(len1, len2);

    // prefix match
    int prefix = 0;
    for (int i = 0; i < minLen; i++) {
        if (s1[i] == s2[i]) {
            prefix++;
        }
    }
    score += (double)prefix / maxLen;

    // double letters
    bool double1 = false;
    bool double2 = false;
    for (int i = 1; i < len1; i++) {
        if (s1[i] == s1[i - 1]) {
            double1 = true;
        }
    }
    for (int i = 1; i < len2; i++) {
        if (s2[i] == s2[i - 1]) {
            double2 = true;
        }
    }
    if (double1 && double2) {
        score += 0.2;
    }

    // same suffixes
    const std::string suffixes[] = { "y", "ie", "ly", "ey", "a", "ah", "ina", "ella", "ette", "ine", "yn", "ee" };
    for (const auto& suf : suffixes) {
        if (len1 >= suf.size() && len2 >= suf.size() &&
            s1.compare(len1 - suf.size(), suf.size(), s2, len2 - suf.size(), suf.size()) == 0) {
            score += 0.2;
            break;
        }
    }

    // same vowel positions
    bool sameVowels = true;
    const std::string vowels = "aeiouy";
    for (int i = 0; i < minLen; ++i) {
        bool v1 = vowels.find(s1[i]) != std::string::npos;
        bool v2 = vowels.find(s2[i]) != std::string::npos;
        if (v1 != v2) {
            sameVowels = false;
            break;
        }
    }
    if (sameVowels) {
        score += 0.2;
    }

    // same letters
    int shared = 0;
    for (char c1 : s1) {
        for (char c2 : s2) {
            if (c1 == c2) {
                shared++;
                break;
            }
        }
    }
    score += 0.3 * ((double)shared / maxLen);

    // same last two letters
    if (len1 >= 2 && len2 >= 2 && s1.substr(len1 - 2) == s2.substr(len2 - 2)) {
        score += 0.2;
    }

    // vowel and consonant positions
    int match = 0;
    for (int i = 0; i < minLen; i++) {
        bool v1 = vowels.find(s1[i]) != std::string::npos;
        bool v2 = vowels.find(s2[i]) != std::string::npos;
        if (v1 == v2) {
            match++;
        }
    }

    score += 0.3 * ((double)match / maxLen);

    // check if lengths are similar
    score += 1.0 - (double)std::abs(len1 - len2) / maxLen;

    return score;
}

void WordSort::prioritize(const std::string& input) {
    heap = Heap<Word, std::greater<Word>>();
    // loop through every word in the list
    for (const auto& word : list) {
        // get score based on input and the word
        double score = heuristic(input, word);
        if (score > 0) {
            // push that word to the heap
            heap.push(Word(word, font, score));
        }
    }
}

std::vector<Word> WordSort::getTopWords(int num) {
    std::vector<Word> result;
    for (int i = 0; i < num; ++i) {
        if (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
    }
    return result;
}
