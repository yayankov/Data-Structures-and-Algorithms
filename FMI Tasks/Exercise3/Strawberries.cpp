#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(long long arr[], long long x, int start, int end)
{
    int middle = start + ((end - start)/2);

    if(end >= start) 
    {
        if(arr[middle] == x)
        {
            return (middle + 1);
        }
        if(arr[middle] > x)
        {
            return binarySearch(arr, x, start, middle - 1);
        }
        if(arr[middle] < x) 
        {
            return binarySearch(arr, x, middle + 1, end);
        }
    }
    return (middle + 1);
}

int main() {
    int n; 
    cin >> n;
    long long input;
    long long a[n] = {0};
    for(int i=0; i<n; i++)
    {
        cin >> input;
        if(i == 0) 
        {
            a[i] = input;
        }
        else a[i] = a[i-1]+input;
    }
    int m; 
    cin >> m;
    long long q[m];
    for(int i=0; i<m; i++)
    {
        cin >> q[i];
    }
    for(int i=0; i<m; i++)
    {
        cout << binarySearch(a, q[i], 0, n-1) << endl;
    }
    return 0;
}
