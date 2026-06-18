# QubeTimer
A Qt desktop application for timing Rubik's Cube solves

## Features

1. Generate a random 3x3 scramble.
2. Start and stop a timer to time your solves.

## Building with CMake

This project uses CMake and Qt, so building it requires those utilities installed.

Compiling the project on Unix[^1] takes the following steps:

1. Clone the repository
```
git clone https://github.com/JooseMann/QubeTimer.git 
cd QubeTimer
```

2. Build with CMake and Make
```
mkdir build
cmake -B build
cd build
make
```

This generates the `QubeTimer` executable in the `build/` directory.

[^1]: I am not sure if these tools differ on Windows, so building there will most likely be at least a little different.

## Project Progress
- [X] A randomly generated 3x3 scramble.
- [X] A running timer that shows the time it takes to solve the cube.
  - [X] Keybinds to start and stop the timer on command.
- [ ] A system that records your solves over time, and computes statistics about them.
- [ ] A scramble display that shows the correct scramble state, to verify that the scramble was done correctly.
- [ ] Allow randomly generated scrambles for other cubes (e.g., 2x2 and 4x4 scrambles).
