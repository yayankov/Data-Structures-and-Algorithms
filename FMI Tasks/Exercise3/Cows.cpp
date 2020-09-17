#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
  
bool isPossible(long long* hut, long long mid, long long size, long long k) 
{ 
    long long pos = hut[0]; 
    long long tempCows = 1;  
    for (unsigned int i=1; i<size; i++) 
    { 
        if (hut[i] - pos >= mid) 
        { 
            pos = hut[i]; 
            tempCows++; 
            
            if (tempCows == k) 
              return true; 
        } 
    } 
    return 0; 
} 
  
long long largestMinDist(long long* hut, long long n, long long k) 
{ 
    long long tempLen = -1; 
    long long start = hut[0];
    long long end = hut[n-1]; 
    while (start < end) 
    { 
        long long middle = (start + end)/2; 
        if (isPossible(hut, middle, n, k)) 
        {  
            if(tempLen < middle)
            {
                tempLen = middle;
            }
            start = middle + 1; 
        } else {
            end = middle; 
        }
    } 
    return tempLen; 
} 

int main() {
    long long N, K;
    cin >> N >> K;
    long long hut[N];
    for(unsigned int i=0; i<N; i++)
    {
        cin >> hut[i];
    }
    sort(hut, hut + N);
    cout << largestMinDist(hut, N, K);
    return 0;
}
