#include <iostream>

using namespace std;

char seats[8][4];
int row = 8;
int col = 4;

void setup()
{
        for (int i=0;i<8;i++)
                for (int k=0;k<col;k++)
                        seats[i][k] = '_';

}

void display()
{
        // first line
        cout<<' ';
        for(int i=1;i <= col; i++)
                cout<<" "<<i;
        for (int i=0; i<row; i++)
        {
                cout<<"\n"<<i+1;
                for (int k=0;k<col;k++)
                        cout<<' '<<seats[i][k];
                cout<<endl;
        }
}
bool isValid(int row, int col)
{
        if (seats[row][col] == '_')
                return true;
        return false;
}

void book()
{
        // get input
        int bookR;
        int bookC;
        cout<<"Please enter the position you want to book (Format row col)--> ";
        cin>>bookR;
        cin>>bookC;
        bookR--;
        bookC--;

        // condition
        if (isValid(bookR, bookC))
        {
                seats[bookR][bookC] = 'X';
                cout<<"\tOrder complete"<<endl;
                display();
        }
        else
                cout<<"\t>>> SB Do you have eys?"<<endl;


}

void exit()
{
        cout<<"Goodbye!"<<endl;
}

void menu()
{
        char choice;
        cout<<"\n\t----> Menu <----"<<endl;
        cout<<"\t1 --> Display current Seats status."<<endl;
        cout<<"\t2 --> Book a seat." <<endl;
        cout<<"\t0 --> Exit Program."<<endl;
        cout<<"Your Choice --> ";
        cin>>choice;
        
        switch (choice)
        {
        case '1': display();menu();break;
        case '2': book();menu();break;
        case '0': exit();break;
        default: cout<<"invalid choice!"<<endl;
        }
}


int main()
{
        setup();
        menu();

}
