#include "Tokenizer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

void Tokenizer::tokenizeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string text = buffer.str();

    // Use regex 
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator begin(text.begin(), text.end(), word_regex);
    std::sregex_iterator end;

    for (auto i = begin; i != end; ++i) {
        std::string word = i->str();
        for (char &ch : word) ch = tolower(ch);
        if (wordToID.find(word) == wordToID.end()) {
            wordToID[word] = currentID;
            idToWord.push_back(word);
            currentID++;
        }
    }
}

int Tokenizer::getToken(const std::string& word) const {
    auto it = wordToID.find(word);
    return (it != wordToID.end()) ? it->second : -1;
}

std::string Tokenizer::getWord(int token) const {
    return (token >= 0 && token < static_cast<int>(idToWord.size())) ? idToWord[token] : "";
}

void Tokenizer::printAllTokens() const {
    for (const auto& pair : wordToID) {
        std::cout << "Word: \"" << pair.first << "\", Token: " << pair.second << "\n";
    }
}
