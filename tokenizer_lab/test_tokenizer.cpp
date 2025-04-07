#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tokenizer.h"

TEST_CASE("Tokenizer loads known words from file") {
    Tokenizer tokenizer;
    tokenizer.tokenizeFromFile("the-verdict.txt");

    CHECK(tokenizer.getToken("head") != -1);
    CHECK(tokenizer.getToken("flowers") != -1);
    CHECK(tokenizer.getToken("jack") != -1);
}

TEST_CASE("getToken returns -1 for unknown words") {
    Tokenizer tokenizer;
    tokenizer.tokenizeFromFile("the-verdict.txt");

    CHECK(tokenizer.getToken("nonexistentword") == -1);
    CHECK(tokenizer.getToken("xyzqrs") == -1);
}

TEST_CASE("getWord returns correct value for valid tokens") {
    Tokenizer tokenizer;
    tokenizer.tokenizeFromFile("the-verdict.txt");

    int token = tokenizer.getToken("self");
    CHECK(token != -1);
    CHECK(tokenizer.getWord(token) == "self");
}

TEST_CASE("getWord returns empty string for invalid tokens") {
    Tokenizer tokenizer;
    tokenizer.tokenizeFromFile("the-verdict.txt");

    CHECK(tokenizer.getWord(-1) == "");
    CHECK(tokenizer.getWord(100000) == ""); 
}

TEST_CASE("Round-trip consistency: word -> token -> word") {
    Tokenizer tokenizer;
    tokenizer.tokenizeFromFile("the-verdict.txt");

    std::string word = "moon";
    int token = tokenizer.getToken(word);
    CHECK(token != -1);
    CHECK(tokenizer.getWord(token) == word);
}
