CC=gcc
CXX=g++
CFLAGS=-Wall -ggdb
CXXFLAGS=$(CFLAGS) --std=c++23
SUBDIRS=lab1 lab2 lab3
MAKEFLAGS += --no-print-directory

export

.PHONY: all clean


all:
	@for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean;\
	done

