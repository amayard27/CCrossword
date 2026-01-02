# CCrossword

A terminal-based crossword puzzle generator written in C. Input either a text file of words or enter your own words to create a crossword puzzle complete with solved and unsolved versions, along with clues.

---

## Table of Contents
1. [Features](#features)
2. [Prerequisites](#prerequisites)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Project Structure](#project-structure)
6. [Example](#example)
7. [Output](#output)
8. [License](#license)

---

## Features

- **Flexible Input**: Accept words from a text file or manual entry
- **Automatic Grid Generation**: Creates crossword grids automatically
- **Dual Output**: Generates both solved and unsolved puzzle versions
- **Clue Generation**: Automatically generates clues for the crossword
- **Terminal-Based**: Runs entirely in the terminal for simplicity
- **Sample Word List**: Includes `ndwords.txt` as an example word list

---

## Prerequisites

To build and run CCrossword, you need:
- **GCC** (or any C compiler)
- **Make** (for building the project)
- A Unix-like environment (Linux, macOS, or WSL on Windows)

---

## Installation

Clone the repository:
```sh
git clone https://github.com/amayard27/CCrossword.git
cd CCrossword
```

Build the project:
```sh
make
```

This will compile the source files and create the `runcrossword` executable.

---

## Usage

### Run with a text file of words:
```sh
./runcrossword ndwords.txt
```

### Run with manual word entry:
```sh
./runcrossword
```
Then follow the prompts to enter your words.

### Input File Format
When using a text file, format it with one word per line:
```
EXAMPLE
CROSSWORD
PUZZLE
TERMINAL
GENERATE
```

---

## Project Structure
```
.
├── Makefile           # Build configuration
├── README.md          # This file
├── crossword.c        # Main program entry point
├── funcword.c         # Core crossword generation functions
├── funcword.h         # Function declarations and structures
├── ndwords.txt        # Example word list
├── output/            # Generated crossword files
├── *.o                # Compiled object files
└── runcrossword       # Executable
```

---

## Example

Running the program with the included word list:
```sh
./runcrossword ndwords.txt
```

The program will:
1. Read the words from the file
2. Generate a crossword grid layout
3. Create solved and unsolved versions
4. Generate clues for each word
5. Save output files to the `output/` directory

---

## Output

Generated files are saved in the `output/` directory:
- **Solved puzzle**: Shows the complete crossword with all letters filled in
- **Unsolved puzzle**: Shows the blank grid with numbers for clues
- **Clues list**: Provides across and down clues for solving

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

## Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests

---

## Author

**Andre Mayard**  
[GitHub: @amayard27](https://github.com/amayard27)