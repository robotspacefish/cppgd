#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();
void displayBoard(const std::vector<char>& board);
char winner(const std::vector<char>& board);

int main() {
    const int NUM_SQUARES = 9;
    // init 9 blank spaces on the board
    std::vector<char> board(NUM_SQUARES, EMPTY);
    
    instructions();
    displayBoard(board);
    return 0;
}

void instructions()
{
    using namespace std;
    
    cout << "Welcome to Tic-Tac-Toe!" << "\n";
    cout << "0 - 8 represent spaces on the board. Enter the number\n";
    cout << "corresponding to the position you want to make your mark in.\n\n";
    
    cout << " 0 | 1 | 2\n";
    cout << "-----------\n";
    cout << " 3 | 4 | 5\n";
    cout << "-----------\n";
    cout << " 6 | 7 | 8\n\n";
}

void displayBoard(const std::vector<char>& board)
{
    using namespace std;
    
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const std::vector<char>& board)
{
    const int WINNING_ROWS[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    
    const int TOTAL_ROWS = 8;
    
    // check if row is not empty and contains all the same value (all 'X' or all 'O')
    for (int row = 0; row < TOTAL_ROWS; row++)
    {
            if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
                (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
                (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
            {
                return board[WINNING_ROWS[row][0]];
            }
    }
    
    // check for tie
    if (std::count(board.begin(), board.end(), EMPTY) == 0)
        return TIE;
    
    
    return NO_ONE;
}
