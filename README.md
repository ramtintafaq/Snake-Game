
# Snake Game

This is a simple Snake game implemented in C++. The game is played in a console window, where the player controls a snake that moves around the board, eats food, and grows longer. The goal is to avoid running into walls or the snake's own body.

## Features

- Control the snake using keyboard input.
- The snake grows longer as it eats food.
- The game ends when the snake hits a wall or itself.
- Simple, terminal-based gameplay.

## How to Run

### Requirements
- A C++ compiler (e.g., `g++`, `clang++`)
- CMake (if you want to build with CMake)

### Instructions
1. Clone the repository:
   \`\`\`bash
   git clone https://github.com/ramtintafaq/Snake-Game.git
   cd Snake-Game
   \`\`\`

2. **Build and run using CMake**:
   If you're using CMake to build the project, follow these steps:

   \`\`\`bash
   mkdir build
   cd build
   cmake ..
   make
   ./SnakeGame
   \`\`\`

3. **Run the executable**:
   If you already have the compiled executable (`Snake.exe`), you can run it directly:

   \`\`\`bash
   ./Snake.exe
   \`\`\`

### Controls
- Use the arrow keys to control the snake's direction.
- The snake moves automatically, and you must guide it to avoid obstacles (`#`) and collect food.

## Project Structure

\`\`\`
Snake-Game/
│
├── cmake-build-debug/       # CMake build output
├── .idea/                   # IDE configuration files (not tracked due to .gitignore)
├── Snake.cpp                # Main source code file
├── Snake.exe                # Executable file
├── snake.txt                # Game instructions or notes
├── CMakeLists.txt           # CMake project configuration file
└── README.md                # Project documentation (this file)
\`\`\`

## Future Improvements

- Add graphical interface instead of console-based gameplay.
- Implement different levels or difficulties.
- Add scoring system to track the player's performance.
- Add power-ups or obstacles to increase difficulty.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

- **Ramtin Tafaghodi** - [ramtintafaq](https://github.com/ramtintafaq)
