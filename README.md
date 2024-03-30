# Chess Project

## Project Overview

This project implements a chess game in C++. It includes the implementation of a chessboard and the logic to handle various chess pieces and their movements. The project is structured into several key files:
- `chessboard.h`: Header file for the chessboard class, defining the structure and functionalities of the chessboard.
- `chessboard.cpp`: Implementation of the chessboard class. Contains the logic for initializing the chessboard, placing pieces, and handling movements.
- `main.cpp`: The main driver code that utilizes the chessboard class to run the game.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To compile and run this project, you will need a C++ compiler that supports C++11 or later. The GCC compiler or Clang on Linux/Mac, and MSVC on Windows, are suitable choices.

### Compiling the Project

1. Open a terminal or command prompt.
2. Navigate to the project directory.
3. Compile the project using the following command:

For GCC or Clang:
```bash
g++ -std=c++11 chessboard.cpp main.cpp -o chessGame
```

For MSVC:
```bash
cl /EHsc chessboard.cpp main.cpp /o chessGame.exe
```

### Running the Project

After compiling the project, you can run the game using the following command:

On Linux/Mac:
```bash
./chessGame
```

On Windows:
```bash
chessGame.exe
```

## Project Files

- `chessboard.h`: Header file for chessboard definitions and declarations.
- `chessboard.cpp`: Contains the implementation of the chessboard class.
- `main.cpp`: Main application entry point, initializes a game instance.

## Contributing

Please read CONTRIBUTING.md for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

- Jash Patel
