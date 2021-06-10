CXX = g++
CPPFLAGS = -g -Wall -std=c++11

all:duck_duck_goose circular


duck_duck_goose: duck_duck_goose.cpp duck_duck_goose.h circular_list_int.cpp
	$(CXX) $(CPPFLAGS) $^ -o duck_duck_goose

circular: list_test.cpp circular_list_int.h circular_list_int.cpp
		$(CXX) $(CPPFLAGS) $^ -o circular

clean: 
	rm -rf duck_duck_goose circular
