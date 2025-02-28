#include <iostream> // X&O GAME , MADE MY : MARAM ALOTAIBI
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

// DISPLAY THE BOARD 
void printBoard() {
    cout << "\n\n";
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl;
}

// FOR ROWS
bool checkWin() {
    
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }
    
    // FOR COLUMNS
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    
    // FOR ANGLES
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
        
    return false;
}

// FOR TIE
bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    int choice;
    bool gameOver = false;
    
    cout <<"X & O GAME\n";
    cout << "PLAYER 1 (X)  -  PLAYER 2 (O)\n\n";
    
    while(!gameOver) {
        printBoard();
        // current player turn
        
        cout << "YOUR TURN " << currentPlayer << "\n ENTER YOUR POSITION (1-9) : ";
        cin >> choice;
        
        // if the input is valid
        if(choice < 1 || choice > 9) {
            cout << "incorrect! Please enter a number between 1 to 9.\n";
            continue;
        }
        
        // Convert selection to matrix coordinates
        
        int row = (choice-1) / 3;
        int col = (choice-1) % 3;
        
        // Verify that the box is empty
        if(board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "This position is alteady taken! please choose another one.\n";
            continue;
        }
        
        // Place the mark in the selected position 
        board[row][col] = currentPlayer;
        
        // who wins
        if(checkWin()) {
            printBoard();
            cout << "\nCongrats! Player " << currentPlayer << " WINS !!\n";
            gameOver = true;
        }
        // if is a tie 
        else if(checkDraw()) {
            printBoard();
            cout << "\n IT IS A TIE ,,, GAME OVER \n ";
            gameOver = true;
        }
        // Switch player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    
    return 0;
}