CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = main.o Tokenizer.o

# Main build target
tokenizer: $(OBJS)
	$(CXX) $(CXXFLAGS) -o tokenizer $(OBJS)

main.o: main.cpp Tokenizer.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Tokenizer.o: Tokenizer.cpp Tokenizer.h
	$(CXX) $(CXXFLAGS) -c Tokenizer.cpp

# Unit test build target
test: test_tokenizer.cpp Tokenizer.cpp Tokenizer.h doctest.h
	$(CXX) $(CXXFLAGS) -o test_tokenizer test_tokenizer.cpp Tokenizer.cpp
	./test_tokenizer

# Clean all compiled files
clean:
	rm -f *.o tokenizer test_tokenizer

