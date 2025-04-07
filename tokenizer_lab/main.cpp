#include "Tokenizer.h"
#include <iostream>
#include <string>

int main() {
    Tokenizer tokenizer;
    tokenizer.tokenizeFromFile("the-verdict.txt");

    std::cout << "\n--- Tokenizer Loaded ---\n";
    tokenizer.printAllTokens();

    std::string word;
    int token;

    std::cout << "\nEnter a word to look up its token: ";
    std::cin >> word;
    std::cout << "Token: " << tokenizer.getToken(word) << "\n";

    std::cout << "\nEnter a token to look up its word: ";
    std::cin >> token;
    std::cout << "Word: " << tokenizer.getWord(token) << "\n";

    return 0;
}
