#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    long long sum;
    int arr[T][2];
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<T; i++)
    {
        sum = arr[i][0] + arr[i][1];
        if(arr[i][0] >= arr[i][1]-1 && sum%2 == 1 && arr[i][0] >= 0 && arr[i][1] <= 1000000000 && arr[i][1] > 1)
        {
            cout<<"yes";
        } else if( arr[i][1] == 1 && arr[i][0] == 0)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
    cout << endl;

    }

    return 0;
}
