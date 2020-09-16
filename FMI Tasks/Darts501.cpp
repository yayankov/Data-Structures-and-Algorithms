#include<iostream>
using namespace std;

int main()
{
    int goal;
    cin >> goal;
    int allPossible[]= {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,50}; //21
    int allCombination[]= {0,1,2,2,3,3,4,4,5,6,6,6,7,8,8,9,9,10,10,11,12,12,12,13,14,14,15,15
                           ,16,16,17,18,18,18,19,20,20,21,22,24,24,25,26,27,28,30,30,32,33,34,36,36,38,39,40,42,45,48,50,51,54,57,60
    }; //63
    int ctr = 0;
    int arrow1, arrow2, arrow3;
    if(goal < 2 || goal > 160)
    {
        cout << ctr;
        return 0;
    }

    for(int k=0; k<21; k++)
    {
        arrow1 = allPossible[k];
        if(arrow1>goal)
        {
            break;
        }
        if( arrow1 == goal )ctr++;
        for(int i=0; i<63; i++)
        {
            arrow2 = allCombination[i] + allPossible[k];
            if(arrow2>goal)
            {
                break;
            }
            if( arrow2 == goal) ctr++;
            for(int j=0; j<63; j++)
            {
                arrow3 = allCombination[j] + allCombination[i] + allPossible[k];
                if(arrow3>goal)
                {
                    break;
                }
                if( arrow3 == goal ) ctr++;

            }
        }
    }
    cout << ctr;
    return 0;
}
