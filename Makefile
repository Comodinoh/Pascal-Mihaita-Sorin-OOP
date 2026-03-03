CC=gcc
CXX=g++
CFLAGS=-Wall -ggdb
CXXFLAGS=$(CFLAGS) --std=c++23
SUBDIRS=lab1 lab2 lab3
MAKEFLAGS += --no-print-directory
GREEN=\033[0;92m
RESET=\033[0m

export

.PHONY: all clean


all:
	@for dir in $(SUBDIRS); do \
		echo -e "$(GREEN)Building $$dir...$(RESET)"; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo -e "$(GREEN)Cleaning $$dir...$(RESET)"; \
		$(MAKE) -C $$dir clean;\
	done

