.PHONY: clean

all: main.o Canvas.o
	$(CXX) $(CXXFLAGS) -o lab3problem2 main.o Canvas.o

main.o: main.cpp

Canvas.o: Canvas.cpp Canvas.h

clean:
	rm -f Canvas.o main.o
	rm -f lab3problem2
