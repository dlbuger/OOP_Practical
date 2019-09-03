#include <iostream>
#include <array>
using namespace std;

array<int,3> sort(array<int,3> myList);
int main()
{
        array<int,3> test = {30,30,10};
        cout<<"Unsorted"<<endl;
        for (auto c:test)
                cout<<c<<" ";

        cout<<"\n\nSorted"<<endl;
        for (auto c:sort(test))
                cout<<c<<" ";


}

array<int,3> sort(array<int,3> myList)
{
        int length = myList.size();
        for(int i=0; i<length;i++)
                for (int k=0; k<length-i;k++)
                        if (myList[k]>myList[k+1])
                        {
                                        int tmp = myList[k];
                                        myList[k] = myList[k+1];
                                        myList[k+1] = tmp;
                        }
        return myList;
}


