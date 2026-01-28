CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -g
BINDIR := bin

# Strip .cpp extension if user provides it
FILE := $(f:.cpp=)
TARGET := $(BINDIR)/$(FILE)

.PHONY: all clean run list

all:
	@mkdir -p $(BINDIR)
	@find . -name "*.cpp" -not -path "./$(BINDIR)/*" -exec $(MAKE) build-each FILE={} \;

build-each:
	@mkdir -p $(dir $(TARGET))
	$(CXX) $(CXXFLAGS) $(FILE) -o $(TARGET)

# Usage: make run f=sort/main   OR   make run f=sort/main.cpp
run:
ifeq ($(f),)
	@echo "Error: Please specify file: make run f=sort/main"
	@exit 1
endif
	@mkdir -p $(dir $(TARGET))
	$(CXX) $(CXXFLAGS) $(FILE).cpp -o $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BINDIR)

list:
	@echo "Available files:"
	@find . -name "*.cpp" -not -path "./$(BINDIR)/*" | sed 's/\.cpp$$//; s|^./||'
