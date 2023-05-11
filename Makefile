# Set the C++ compiler to use
CXX = g++

# Set the flags to use when compiling C++ files
CXXFLAGS = -Wall -Wextra -std=c++17

# Set the flags to use when linking object files
LDFLAGS = 

# Set the directories to search for header files
INCLUDES = $(shell find Heli -type d -print | sed 's/^/-I/') -I./Assets/Scripts

# Find all .cpp files in the Heli and Assets/Scripts directories, as well as the main.cpp file
SOURCES = $(shell find Heli Assets/Scripts -name '*.cpp') main.cpp

# Generate a list of object files by replacing .cpp with .o in the list of source files
OBJECTS = $(SOURCES:.cpp=.o)

# Set the name of the final executable
EXECUTABLE = program.out

# Default target: build the final executable
all: $(EXECUTABLE)

# Rule to build the final executable by linking all object files
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

# Pattern rule to build an object file from a .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Target to clean up generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Declare all and clean as phony targets (not associated with a file)
.PHONY: all clean