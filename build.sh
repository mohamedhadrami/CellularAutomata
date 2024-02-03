#!/bin/bash

# Set default compiler options
compiler=""
source_file="main.cpp"
output_executable="main"
libraries="Automatons/CellularAutomaton.cpp Automatons/GameOfLife.cpp Automatons/Rule30.cpp Automatons/LangtonsAnt.cpp Automatons/BriansBrain.cpp"
#compiler_flags="-std=c++11 -Wall"

# Function to display a message in green color
print_success() {
    echo -e "\e[32m$1\e[0m"
}

# Function to display a message in red color
print_error() {
    echo -e "\e[31m$1\e[0m"
}

# Detect operating system
if [[ "$OSTYPE" == "linux-gnu"* || "$OSTYPE" == "darwin"* ]]; then
    # Linux and macOS
    compiler="/usr/bin/g++"
elif [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
    # Windows (MINGW)
    compiler="/mingw64/bin/g++"
else
    print_error "Unsupported operating system: $OSTYPE"
    exit 1
fi

# Compile main.cpp and generate executable main
$compiler $source_file -o $output_executable $libraries

if [ $? -eq 0 ]; then
    print_success "Compilation successful. Executable '$output_executable' generated."
else
    print_error "Compilation failed. Please check for errors."
    exit 1
fi
