CC=gcc
CXX=g++
CFLAGS=-Wall -g
SUBDIRS=lab1 lab2
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

