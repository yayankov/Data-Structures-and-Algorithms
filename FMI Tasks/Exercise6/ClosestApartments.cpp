#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define MAX_POINTS 5000000

struct Point
{
    long long x;
    long long y;
    double dist;
};

class MaxHeap
{
    public: 
    long long size; 
    Point* arr; 

      MaxHeap(long long size, Point input[]) 
      { 

          this->size = size; 
          this->arr = input; 

         for (long long i = size / 2 - 1; i >= 0; i--)
         { 
            heapify(arr,size,i); 
         }  
      } 

    void heapify(Point arr[], long long n, long long i) 
    { 
        long long largest = i; 
        long long l = 2*i + 1; 
        long long r = 2*i + 2; 

        if (l < n && arr[l].dist >= arr[largest].dist) 
            largest = l;
        
        if (r < n && arr[r].dist >= arr[largest].dist) 
            largest = r; 

        if (largest != i) 
        { 
            swap(arr[i], arr[largest]); 
            heapify(arr, n, largest); 
        } 
    }  
    
    void heapSort(Point arr[], long long n) 
    { 
        for (long long i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i); 

        for (long long i=n-1; i>=0; i--) 
        { 
            swap(arr[0], arr[i]); 

            heapify(arr, i, 0); 
        } 
    }   
};

void FirstKelements(Point arr[],long long size,long long k){ 
    
    MaxHeap* m = new MaxHeap(k, arr); 

    for (long long i = k; i < size; i++) { 

        if (arr[0].dist < arr[i].dist) 
            continue; 

        else { 
            arr[0] = arr[i]; 
            m->heapify(arr,k,0); 
        } 
    } 
    m->heapSort(arr,k);
    for (long long i = 0; i<k ; i++) { 
        cout <<arr[i].x << " " << arr[i].y << endl; 
    } 
}

int main() {
   ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    
    long long N, K;
    cin >> N >> K;
    long long X,Y;
    double distance;
    
    Point* arr = new Point[MAX_POINTS];
    
    for(int i=0; i<N; i++)
    {
        cin >> X >> Y;
        distance = sqrt(abs(X*X)+abs(Y*Y));
        Point temp = {X, Y, distance};
        arr[i] = temp;
    }
    FirstKelements(arr, N, K);
    return 0;
}
