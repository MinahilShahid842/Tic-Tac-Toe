#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    string playerX, playerO;

public:
    TicTacToe(const string& nameX, const string& nameO) : playerX(nameX), playerO(nameO) {
        board = {{'1', '2', '3'},
                 {'4', '5', '6'},
                 {'7', '8', '9'}};
        currentPlayer = 'X';
    }

    void displayGameScreen() {
        system(CLEAR_COMMAND);
        printRules();
        cout << "\nPlayer X: " << playerX << "  |  Player O: " << playerO << "\n\n";
        printBoard();
    }

    void printRules() {
        cout << "\e[1;32mRules of Tic-Tac-Toe:\e[0m\n\n";
        cout << "1. The game is played on a 3x3 grid.\n";
        cout << "2. Players take turns to place their mark (X or O) in an empty cell.\n";
        cout << "3. The first player to get 3 marks in a row (horizontally, vertically, or diagonally) wins.\n";
        cout << "4. If all 9 cells are filled and no player has 3 marks in a row, the game ends in a draw.\n";
        cout << "5. Enter the number corresponding to the cell you want to mark (1-9).\n";
    }

    void printBoard() {
        cout << "\e[1;35m\nTic-Tac-Toe Board\n\e[0m";
        cout << "-------------\n\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    cout << " \033[1;31m" << board[i][j] << "\033[0m ";
                } else if (board[i][j] == 'O') {
                    cout << " \033[1;34m" << board[i][j] << "\033[0m ";
                } else {
                    cout << " " << board[i][j] << " ";
                }
                if (j < 2) cout << "\033[0;33m|\033[0m";
            }
            cout << endl;
            if (i < 2) cout << "\033[0;33m---|---|---\033[0m\n";
        }
        cout << endl;
    }

    int getValidMove() {
        int move;
        while (true) {
            cout << "Player " << (currentPlayer == 'X' ? playerX : playerO) << " ("
                 << (currentPlayer == 'X' ? "\033[1;31mX\033[0m" : "\033[1;33mO\033[0m")
                 << "), enter your move (1-9): ";
            cin >> move;
            if (cin.fail() || move < 1 || move > 9) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
            } else {
                int row = (move - 1) / 3;
                int col = (move - 1) % 3;
                if (board[row][col] != 'X' && board[row][col] != 'O') {
                    return move;
                } else {
                    cout << "Invalid move! The cell is already occupied. Try again.\n";
                }
            }
        }
    }

    int getAIMove() {
        vector<int> availableMoves;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    availableMoves.push_back(i * 3 + j + 1);
                }
            }
        }
        return availableMoves[rand() % availableMoves.size()];
    }

    bool makeMove(int move) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void resetBoard() {
        board = {{'1', '2', '3'},
                 {'4', '5', '6'},
                 {'7', '8', '9'}};
    }

    void play(bool isAI) {
        int move;
        bool gameEnded = false;
        displayGameScreen();
        while (!gameEnded) {
            if (currentPlayer == 'X' || !isAI) {
                move = getValidMove();
            } else {
                move = getAIMove();
                cout << "AI chooses: " << move << "\n";
            }
            makeMove(move);
            displayGameScreen();

            if (checkWin()) {
                cout << "Congratulations " << (currentPlayer == 'X' ? playerX : playerO) << "! You win!\n";
                gameEnded = true;
            } else if (checkDraw()) {
                cout << "It's a draw!\n";
                gameEnded = true;
            } else {
                switchPlayer();
            }
        }

        char playAgain;
        while (true) {
            cout << "Do you want to play again? Press 'y' for yes, 'n' for no, or '9' to return to the main menu: ";
            cin >> playAgain;
            if (tolower(playAgain) == 'y') {
                resetBoard();
                play(isAI);
                break;
            } else if (tolower(playAgain) == 'n' || playAgain == '9') {
                break;
            } else {
                cout << "Invalid input! Please enter 'y', 'n', or '9'.\n";
            }
        }
    }
};

void displayMainMenu() {
    system(CLEAR_COMMAND);
    cout << "\033[1;36m=========================================================\n";
    cout << "||                                                     ||\n";
    cout << "||       \033[1;33m*** WELCOME TO THE TIC-TAC-TOE GAME ***\033[1;36m       ||\n";
    cout << "||                                                     ||\n";
    cout << "=========================================================\n";
    cout << "\033[0m\n";
    cout << "\033[1;34m                     === MAIN MENU ===\n\033[0m";
    cout << "\033[1;36m---------------------------------------------------------\033[0m\n";
    cout << "\033[1;32m                     1. Play with a Friend\n"
         << "                     2. Play with AI\n"
         << "                     3. Exit\n\033[0m";
    cout << "\033[1;36m---------------------------------------------------------\033[0m\n";
    cout << "\033[1;33m\n             Please enter your choice (1, 2, or 3):\033[0m ";
}

int main() {
    srand(time(0));
    while (true) {
        displayMainMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            string playerX, playerO;
            cout << "Enter Player X's name: ";
            cin >> playerX;
            cout << "Enter Player O's name: ";
            cin >> playerO;
            TicTacToe game(playerX, playerO);
            game.play(false);
        } else if (choice == 2) {
            string playerX;
            cout << "Enter your name: ";
            cin >> playerX;
            TicTacToe game(playerX, "AI");
            game.play(true);
        } else if (choice == 3) {
            cout << "Thanks for playing! Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
