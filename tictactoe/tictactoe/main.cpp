#include <iostream>
#include <string>
#include <vector>

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();
void displayBoard(const std::vector<char>& board);

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
