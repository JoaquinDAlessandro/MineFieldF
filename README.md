# MINEFIELD
Minefield is a 1v1 strategic game developed in C++.
---
# DESCRIPTION

- Minesweeper-style board (shared between both players)
- Board size is defined by the user:
  - Neither axis can be smaller than 10 or larger than 50
  - Each axis may have different size
- Number of mines is also user-defined:
  - Must be between 3 and 8 inclusive
- Game is played by two players:
  - Player 1: Human
  - Player 2: CPU *(Bonus: hotseat mode for PvP in the future)*
- Each turn, both players:
  - Re-place all their remaining mines
  - Enter their guesses simultaneously
  - After both players finish, results are processed
- Rules:
  - Mines placed on already guessed or revealed cells are not allowed
  - If both players place a mine on the same cell, both are lost
  - Guessing a cell with your own mine removes it from your stock
  - Each guessed cell becomes permanently disabled
- Victory conditions:
  - First player to detect all opponent mines wins
  - If both discover the last mines simultaneously, the game is a draw
---
# REQUIREMENTS
- C++11 or newer
---
# COMPILATION
clang++ -std=c++20 -Wall -o minefield.exe \
main.cpp Game.cpp Board.cpp Coordinate.cpp Mine.cpp Player.cpp \
StatePattern/SetupState.cpp StatePattern/PlacingMinesState.cpp \
StatePattern/GuessingState.cpp StatePattern/ProcessingState.cpp \
StatePattern/GameOverState.cpp \
Logic/PlacingLogic.cpp Logic/GuessingLogic.cpp \
PlayerInitializers/PlayerInitializers.cpp

./minefield.exe

# PROJECT STRUCTURE
GAME/
├── Board.cpp / Board.h
├── Coordinate.cpp / Coordinate.h
├── Game.cpp / Game.h
├── Mine.cpp / Mine.h
├── Player.cpp / Player.h
└── main.cpp
│
├── Logic/
│   ├── GuessingLogic.cpp / .h
│   └── PlacingLogic.cpp / .h
│
├── PlayerInitializers/
│   └── PlayerInitializers.cpp / .h
│
├── StatePattern/
│   ├── SetupState.cpp / .h
│   ├── PlacingMinesState.cpp / .h
│   ├── GuessingState.cpp / .h
│   ├── ProcessingState.cpp / .h
│   ├── GameOverState.cpp / .h
│   └── GameState.cpp / .h
│
└── README.md
