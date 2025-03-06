CC := g++
CC_ARGS := -Wall -pedantic
SOURCES := main.cc
OBJECTS := $(SOURCES:.cc=.o)
EXECUTABLE := despair
CLANG_TIDY_CHECKS := bugprone-*,readability-*,modernize-*,performance-*,portability-*,clang-analyzer-*
CLANG_FORMAT_STYLE := WebKit

.PHONY: all
all: $(EXECUTABLE)

%.o: %.c
	$(CC) $(CC_ARGS) -c $< -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CC_ARGS) -o $@ $^

.PHONY: tidy
tidy:
	clang-tidy $(SOURCES) --checks="$(CLANG_TIDY_CHECKS)" --fix --fix-errors -- -I.

.PHONY: format
format:
	clang-format -i --style=$(CLANG_FORMAT_STYLE) $(SOURCES) *.h

lint: tidy format
	echo "lint + format"

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: clean
clean:
	rm -f -- $(OBJECTS) $(EXECUTABLE)
