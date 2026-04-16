🎮 Tic-Tac-Toe Game (C++ Console)
A beginner-friendly console-based Tic-Tac-Toe game built in C++ using Code::Blocks.
Play against a friend or challenge a simple AI opponent that makes random moves using rand().

Developed as a first-semester project in collaboration with Eman Fatima.

✨ Features
🎨 Colored console output for better visual experience

👥 Two game modes:

Player vs. Friend (local two-player)

Player vs. computer (computer uses random moves)

📜 Rules displayed at game start

🧠 Input validation – handles invalid moves and non-numeric input

🔁 Play again option after each game

🧼 Cross-platform – works on Windows (cls) and Linux/macOS (clear)

🕹️ How to Play
Players take turns placing their mark (X or O) on a 3×3 grid.

The board cells are numbered 1 to 9 (left to right, top to bottom).

Enter the number of the cell you want to claim.

First to get three in a row (horizontal, vertical, or diagonal) wins.

If all 9 cells are filled with no winner, the game ends in a draw.

🛠️ Compilation & Execution
Prerequisites
A C++ compiler (g++, MinGW, MSVC, etc.)

Code::Blocks (recommended) or any IDE / terminal

Compile (using g++)
bash
g++ tictactoe5.cpp -o tictactoe
Run
bash
./tictactoe      # Linux/macOS
tictactoe.exe    # Windows
⚠️ The program uses system("cls") / system("clear"). On some Unix systems you may need to run from a standard terminal.

📂 Project Structure
text
├── tictactoe5.cpp   # Main source code
└── README.md        # This file
🧪 Example Gameplay
text
=========================================================
||       *** WELCOME TO THE TIC-TAC-TOE GAME ***       ||
=========================================================

                 === MAIN MENU ===
---------------------------------------------------------
                 1. Play with a Friend
                 2. Play with AI
                 3. Exit
---------------------------------------------------------
🤝 Credits
Developer: Minahil Shahid

Collaborator: Eman Fatima

