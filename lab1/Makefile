PROBLEMS=problem1 problem2 problem3 extra

.phony: all clean


all:
	@for dir in $(PROBLEMS); do\
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(PROBLEMS); do \
		echo "Cleaning $$dir..."; \
		$(MAKE) -C $$dir clean; \
	done
