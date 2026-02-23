.PHONY: clean

all: main.o NumberList.o
	$(CXX) $(CFLAGS) -o lab2problem1 main.o NumberList.o

main.o: main.cpp
NumberList.o: NumberList.cpp

clean:
	rm -f main.o NumberList.o
	rm -f lab2problem1
