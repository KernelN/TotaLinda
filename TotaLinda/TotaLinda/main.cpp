#include <iostream>
#define MAX 7

using namespace std;

int main()
{
    int arrayNum [MAX]={3, 44, 65, 42, 79, 78, 33};
    bool arrayBool [MAX]={1, 0, 0, 1, 1, 0, 0};
    char finalArray[4*MAX]="(3&44|33)&(!79|78)";
    int position[MAX];
    char conector[MAX];


    short j=0;
    short l=0;
    for (short i=0;i<4*MAX;i++)
    {
        if (finalArray[i]==40 || finalArray[i]==41)
        {
            position[j]=i;
            j++;
        }


        switch (finalArray[i])
        {
            case 38:
                conector[j]= '&';
                l++;
                break;
            case 124:
                conector[j]= '|';
                l++;
                break;
            case 33:
                conector[j]= '!';
                l++;
                break;
            case 40: case 41:
                position[j]=i;
                j++;
            default:
                break;

        }

    }



//    for (int h=0;h<=j;h+=2)
//    {
//
//    }
    int i=1;
    for (int h=0;i<position[2*i];h++)
    {

    }

    return 0;
}
