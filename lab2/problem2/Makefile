.PHONY: clean

all: main.o Student.o StudentCompare.o
	$(CXX) $(CFLAGS) -o lab2problem2 main.o Student.o StudentCompare.o

main.o: main.cpp
Student.o: Student.cpp
StudentCompare.o: StudentCompare.cpp

clean:
	rm -f main.o Student.o StudentCompare.o
	rm -f lab2problem2
