CC=gcc
CXX=g++
FLAGS=-Wall -g

all: l1p1 l1p2 l1p3

l1p1: lab1problema1.c
	$(CC) $(FLAGS) -o lab1problema1 lab1problema1.c
l1p2: lab1problema2.c
	$(CC) $(FLAGS) -o lab1problema2 lab1problema2.c
l1p3: lab1problema3.cpp
	$(CXX) $(FLAGS) -o lab1problema3 lab1problema3.cpp
