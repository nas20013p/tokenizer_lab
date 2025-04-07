#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>
#include <vector>

class Tokenizer {
private:
    std::unordered_map<std::string, int> wordToID;
    std::vector<std::string> idToWord;
    int currentID = 0;

public:
    void tokenizeFromFile(const std::string& filename);
    int getToken(const std::string& word) const;
    std::string getWord(int token) const;
    void printAllTokens() const;
};

#endif
