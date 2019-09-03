//Searches a partially filled array of nonnegative integers.
#include <iostream>

using namespace std;

const int DECLARED_SIZE = 10;

void fillArray(int a[], int size, int& numberUsed) {
    cout << "Enter up to " << size << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index;
}

int search(const int a[], int numberUsed, int target, int index)
{
    bool found = false;
    while ((!found) && (index < numberUsed))
    if (target == a[index])
        found = true;
    else
        index++;

    if (found)
        return index;
    else
        return -1;
}

int main( )
{
    int arr[DECLARED_SIZE], listSize, target;

    fillArray(arr, DECLARED_SIZE, listSize);

    char ans;
    do
    {
        int result = 0;
        cout << "Enter a number to search for: ";
        cin >> target;
        do{
        result = search(arr, listSize, target, result);
        if (result == -1)
            {cout << target << " is not on the list.\n"; break;}
        else
        {
            cout << target << " is stored in array position " 
                 << result << endl
                 << "(Remember: The first position is 0.)\n";
            result++;
        }
        }while (result  < listSize);
        cout << "Search again?(y/n followed by return): ";
        cin >> ans;
    } while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";
    return 0;
}
