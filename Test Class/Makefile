CXX = g++
CXXFLAGS = -Wall

.DELETE_ON_ERROR:
output: test_my_class.o my_class.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test_my_class.o: test_my_class.cpp test_my_class.hpp my_class.o
	$(CXX) $(CXXFLAGS) -c test_my_class.cpp -o test_my_class.o

my_class.o: my_class.cpp my_class.h
	$(CXX) $(CXXFLAGS) -c my_class.cpp -o my_class.o

.PHONY: clean
clean:
	rm -f *.o
	rm -f *.exe