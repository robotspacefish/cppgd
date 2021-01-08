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

int main() {
   
    instructions();
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
