#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;

void display();

const int ROWS=3;
const int COLS=4;

int table[ROWS][COLS];

int main() {
        srand(time(0));


        for (int i = 0; i < ROWS; i ++) {
                for (int j = 0; j < COLS; j++)   {
                        table[i][j] = rand()%3-1;
                }
        }

        for (int i = 0; i < ROWS; i ++)  {
                for (int j = 0; j < COLS; j++)
                        cout << setw(3) << table[i][j];

                cout << endl;
        }

        display();
}

void display()
{   
        int row;
        int col;
        cout<<"Please enter the row number --> ";
        cin>>row;
        cout<<endl;

        cout<<"Please enter the col number --> ";
        cin>> col;
        cout<<endl;

        cout<<"Current Position --> "<<table[row-1][col-1]<<endl;
        row -= 1;
        col -= 1;

        if(row == 0)
                cout<<"There is no number up"<<endl;
        else 
                cout<<"Up    --> "<< table[row-1][col]<<endl;

        if (row == 2)
                cout<<"There is no number down"<<endl;
        else
                cout<<"Down  --> "<< table[row+1][col]<<endl;
        

        if (col == 0)
                cout<<"There is no number left"<<endl;
        else
                cout<<"Left  --> "<< table[row][col-1]<<endl;

        if (col == 3)
                cout<<"There is no number right"<<endl;
        else
                cout<<"Right --> "<< table[row][col+1]<<endl;
}
