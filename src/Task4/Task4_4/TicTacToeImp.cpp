

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip>

#include "TicTacToe.h"

using namespace std;
int counter = 0;
void ticTacToe::play()
{
    bool done = false;
    char player = 'X';

    displayBoard();

    while (!done)
    {
        done = getXOMove(player);

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

void ticTacToe::displayBoard() const
{
    cout << "   1    2    3" << endl << endl;

    for (int row = 0; row < 3; row++)
    {
        cout << row + 1;

        for (int col = 0; col < 3; col++)
        {
            cout << setw(3) << board[row][col];

            if (col != 2)
                cout << " |";
        }

        cout << endl;

        if (row != 2)
            cout << " ____|____|____" << endl
                << "     |    |    " << endl;
    }

    cout << endl;
}

bool ticTacToe::isValidMove(int x, int y) const
{
    if (y <= 2 && x <= 2 && board[x][y] == ' ')
    {
        return true;
    }
    else{
        cout<<"Invalid Move ! Try Again!"<<endl;
        return false;
    }
}


bool ticTacToe::getXOMove(char playerSymbol)
{
    int row, col;

    do 
    {
        cout << "Player " << playerSymbol 
            << " enter move: ";
        cin >> row >> col;
        cout << endl;
    }
    while (!isValidMove(row - 1, col - 1) );

    row--;
    col--;

    noOfMoves++;

    board[row][col] = playerSymbol;
    displayBoard();

    status gStatus = gameStatus();

    if (gStatus == WIN)
    {
        cout << "Player " << playerSymbol << " wins!" << endl;
        return true;
    }
    else if (gStatus == DRAW)
    {
        cout << "This game is a draw!" << endl;
        return true;
    }
    else if(noOfMoves >= 9) {
        return true;
    } else
        return false;
}

status ticTacToe::gameStatus()
{
    //if ((a = 'X' || a == 'O' ) && a = a+1 && a = a+2)
    //return WIN; 
    counter ++;
    for(int i=0;i<3;i++)
    {
        if((board[i][0] == 'X' || board[i][0] == 'O') && (board[i][0] == board[i][1]) && (board[i][1]== board[i][2]))
            return WIN;
        if((board[0][i] == 'X' || board[0][i] == 'O') && (board[0][i] == board[1][i]) && (board[2][i]== board[1][i]))
            return WIN;
    }
    if((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][0] == board[1][1]) && (board[2][2]== board[1][1]))
    return WIN;
    if((board[0][2] == 'X' || board[0][2] == 'O') && (board[0][2] == board[1][1]) && (board[2][0]== board[1][1]))
    return WIN;
    //Draw:
    // counter == 9 
    if (counter == 9)
        return DRAW;
    return CONTINUE;
}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
