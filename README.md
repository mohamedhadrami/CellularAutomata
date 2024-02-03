# CellularAutomata

*CellularAutomata* is a command-line tool for simulating various cellular automata, offering a dynamic exploration of patterns and behaviors. Customize simulations with ease, choosing from automaton types and adjusting frames per second for a captivating experience.

## Installation

Clone the repository:
```bash
git clone https://github.com/mohamedhadrami/CellularAutomata.git
cd your-repo
```
Run the build script to compile the code and create the executable:
```bash
chmod +x build.sh
./build.sh
```

Before running the build script, make sure to update the compiler 
variable in the build.sh file to your compiler path. The script 
attempts to detect the operating system and sets the compiler 
accordingly.

```bash
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
```

## Usage

After building the program, you can use it with the following options:

```bash
./main [options]
```

**Options**:

* -h or --help: Display usage instructions.
* -v or --version: Display the version of the program.
* -i or --info: Display additional information.
* -a or --automaton: Specify the automaton type. Available types:
    * gameoflife
    * rule30
    * langtonsant
    * briansbrain
* -f or --fps: Specify the frames per second (default: 10).

**Examples**:

```bash
# Run the program with default values
./main rule30

# Specify the automaton type and frames per second
./main -a gameoflife -f 15
```

## Adding your own Automaton

Create a header file and a C++ file

## Contributing
* Fork the repository.
* Create a new branch: `git checkout -b feature-branch`.
* Make changes and commit: `git commit -m "Add new feature"`.
* Push to the branch: `git push origin feature-branch`.
* Submit a pull request.

## License
This project is licensed under the [MIT License](./LICENSE).
