.PHONY: clean

all: main.o Math.o
	$(CXX) $(CXXFLAGS) -o lab3problem1 Math.o main.o

main.o: main.cpp

Math.o: Math.cpp Math.h

clean:
	rm -f main.o Math.o
	rm -f lab3problem1
