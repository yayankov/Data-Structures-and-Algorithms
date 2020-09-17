#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    int tempS = 0;
    int S = 0;
    int best2 = 0;
    int best = 0;
    int road = 0;
    int road2 = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            road = abs(i-j);
            if(a[i] > a[j])
            {
                tempS = a[j]*road;
            }
            else{
                tempS = a[i]*road;
            }
            if(S < tempS)
            {
                S = tempS;
            }
        }

    }
    cout << S;

    return 0;
}
