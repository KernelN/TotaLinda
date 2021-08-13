#include <iostream>
#define MAX 7

using namespace std;

int main()
{
    int arrayNum [MAX]={3, 44, 65, 42, 79, 78, 33};
    bool arrayBool [MAX]={1, 0, 0, 1, 1, 0, 0};
    char finalArray[4*MAX]="(3&44|33)&(!79|78)";
    int position[MAX];

    short j=0;
    for (short i=0;i<4*MAX;i++)
    {
        if (finalArray[i]==40 || finalArray[i]==41)
        {
            position[j]=i;
            j++;
        }
    }


    return 0;
}
