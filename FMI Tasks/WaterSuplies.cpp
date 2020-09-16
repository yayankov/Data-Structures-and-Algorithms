#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int tempS=0;
    int S=0;
    int best2=0;
    int best=0;
    int road=0;
    int road2=0;
    for(int i=0; i<n; i++)
    {
      /*  if(best< a[i)+i )
        {
            best=a[i];
            cout<<" best:"<<best<<endl;
        }
        if(best2<(a[i]+abs(i-road)))
        {
            best2=a[i];
            road2=abs(i-road);
        cout<<" best2:"<<best2<<endl;

        cout<<" road:"<<road2<<endl;

        }
        if(best>best2)
        {
            tempS=best*road2;
        }
        else
        {
            tempS=best2*road2;

        }
        if(S<tempS)
        {
            S=tempS;
        }*/

        for(int j=0;j<n;j++)
        {
            road=abs(i-j);
            if(a[i]>a[j])
            {
                tempS=a[j]*road;
            }
            else{
                tempS=a[i]*road;
            }
            if(S<tempS)
            {
                S=tempS;
            }
        }

    }
    cout<<S;

    return 0;
}
