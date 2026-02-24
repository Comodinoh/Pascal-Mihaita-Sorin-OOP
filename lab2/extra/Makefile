.PHONY: clean

CXXFLAGS=--std=c++20

all: main.o Movie.o MovieCmp.o MovieSeries.o
	$(CXX) $(CFLAGS) --std=c++20 -o lab2extra main.o Movie.o MovieCmp.o MovieSeries.o

main.o: main.cpp

Movie.o: Movie.cpp

MovieCmp.o: MovieCmp.cpp

MovieSeries.o: MovieSeries.cpp

clean:
	rm -f main.o Movie.o MovieCmp.o MovieSeries.o

