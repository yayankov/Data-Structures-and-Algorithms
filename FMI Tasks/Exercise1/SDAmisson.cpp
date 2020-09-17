#include<iostream>
using namespace std;
int main()
{
    int M;
    cin >> M;
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }
    long long ctrPlus = 0;
    long long ctrMinus = 0;
    for(int i=0; i<N; ++i)
    {
        if(A[i] > M)
        {
            while(A[i] > M)
            {
                ctrPlus++;
                A[i]--;
            }
        } else if(A[i] < M)
        {
            while(A[i] < M)
            {
                ctrMinus--;
                A[i]++;
            }
        }

    }
    if(ctrPlus+ctrMinus >= 0)
        {
          cout << "yes";
        }
    else cout << "no";
    return 0;
}

