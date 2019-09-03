

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip>

#include "TicTacToe.h"

using namespace std;
int counter = 0;
const int SIZE = 5;
char board[SIZE][SIZE];
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
    for(int i=0; i< SIZE; i++)
        cout<<"   "<<i+1<<' ';
    cout<<endl<<endl;
    for (int row = 0; row < SIZE; row++)
    {
        cout << row + 1;

        for (int col = 0; col < SIZE; col++)
        {
            cout << setw(4) << board[row][col];
            if (col != SIZE-1)
                cout << "|";
        }
        cout<<endl<<" ";
        if (row != SIZE-1)
        {
            for (int i=0;i<SIZE;i++)
            {
                if(i != SIZE-1)
                    cout<<"____|";
                else
                    cout<<"____";
            }
            cout<<endl;
            cout<<" ";
            for (int i =0; i<SIZE;i++)
                if (i != SIZE-1)
                    cout<<setw(5)<<"|";
            cout<<endl;
        }
    }
    cout << endl;
}

bool ticTacToe::isValidMove(int x, int y) const
{
    if (y < SIZE && x < SIZE && board[x][y] == ' ')
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
    else if(noOfMoves >= SIZE*SIZE) {
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
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
