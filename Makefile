CC=gcc
FLAGS=-Wall -g

all: l1p1 l1p2

run: l1p1 l1p2
	./lab1problema1
	@echo --------------------
	./lab1problema2

l1p1: lab1problema1.c
	$(CC) $(FLAGS) -o lab1problema1 lab1problema1.c
l1p2: lab1problema2.c
	$(CC) $(FLAGS) -o lab1problema2 lab1problema2.c
