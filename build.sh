#!/bin/bash

# Set compiler options
compiler="/usr/bin/g++"
source_file="main.cpp"
output_executable="main"
libraries="CellularAutomaton.cpp GameOfLife.cpp"
compiler_flags="-std=c++11 -Wall"

# Function to display a message in green color
print_success() {
    echo -e "\e[32m$1\e[0m"
}

# Function to display a message in red color
print_error() {
    echo -e "\e[31m$1\e[0m"
}

# Compile main.cpp and generate executable main
$compiler $compiler_flags $source_file -o $output_executable

if [ $? -eq 0 ]; then
    print_success "Compilation successful. Executable '$output_executable' generated."
else
    print_error "Compilation failed. Please check for errors."
    exit 1
fi

# Optionally, run the executable
if [ -x "$output_executable" ]; then
    clear
    ./$output_executable
else
    print_error "Executable '$output_executable' not found. Please check for compilation errors."
    exit 1
fi