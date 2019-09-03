
#include <iostream>

class OneDArray
{

private:
    const int SIZE = 10;
    int numerUsed;
    int target;
    int myList[10];
    int input, index = 0;
    int trackIndex = 0;
public:
    OneDArray()
    {
        initializeArray();
        run();
    }

private:
    void initializeArray()
    {
        std::cout << "Enter up to " << SIZE << " nonnegative whole numbers.\n"
            << "Mark the end of the list with a negative number.\n";

        do{
            std::cin>>input;
            myList[index] = input;
            index++;
        }while(input >= 0 && index<SIZE);
    }

    int search(int target, int startIndex)
    {   

        for (int i = startIndex; i<index; i++)
        {
            if(myList[i] == target)
                return i;
            trackIndex = i;
        }
        return -1;

    }
    void run()
    {
        char ans='y';
        int numberFound = 0;
        do 
        {
            int result = 0;
            std::cout<<"Please enter the targer number --> ";
            std::cin>>target;
            result = search(target, result);
            if(result == -1 && numberFound == 0)
                std::cout<<"There is no such a number!"<<std::endl;
            else
            {
                std::cout<< target << " number's location is "<< result<<std::endl;
                numberFound++;
            }
            while(trackIndex < index - 1)
            {
                result = search(target, result+1);
                if(result != -1)
                    std::cout<<target << " number's lacation is: " << result<<std::endl;
                numberFound++;
            }
            trackIndex = 0;
            std::cout<<"Search again?(y/n followed by return): ";
            std::cin >> ans;
        }
        while(ans != 'n' || ans != 'N');
    }
};

int main()
{
    OneDArray();
}
