PROBLEMS=problem1 problem2 problem3 extra

.PHONY: all clean

all:
	@for dir in $(PROBLEMS); do\
		echo -e "$(GREEN)Building $$dir...$(RESET)"; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(PROBLEMS); do \
		echo -e "$(GREEN)Cleaning $$dir...$(RESET)"; \
		$(MAKE) -C $$dir clean; \
	done
