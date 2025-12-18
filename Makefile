CC := g++
CC_ARGS := -g -Wall -Wextra -pedantic -I./ -std=c++20
SOURCES := main.cc node.cc type.cc
OBJECTS := $(SOURCES:.cc=.o)
EXECUTABLE := despair

.PHONY: all
all: $(EXECUTABLE)

%.o: %.cc
	$(CC) $(CC_ARGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CC_ARGS) -o $@ $^

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: clean
clean:
	rm -f *.o $(EXECUTABLE)
