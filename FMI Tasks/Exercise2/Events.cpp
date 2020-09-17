#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int * originalArray,int *arr2, int * mergeArray,int * mergeArray2, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    for (int i = start; i <= end; i++) {
        if (left <= mid && (right > end || originalArray[left] <= originalArray[right])) {
            mergeArray[i] = originalArray[left];
            mergeArray2[i] = arr2[left];
            left++;
        } else {
            mergeArray[i] = originalArray[right];
            mergeArray2[i] = arr2[right];
            right++;
        }
    }

    for (int i = start; i <= end; i++) {
        arr2[i] = mergeArray2[i];
        originalArray[i] = mergeArray[i];
    }
}

void _mergeSort(int * originalArray,int *arr2, int * mergeArray,int *mergeArray2, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;

        _mergeSort(originalArray,arr2, mergeArray,mergeArray2, start, mid);
        _mergeSort(originalArray,arr2, mergeArray,mergeArray2, mid + 1, end);

        merge(originalArray,arr2, mergeArray,mergeArray2, start, mid, end);
    }
}

void mergeSort(int * arr, int* arr2,int length) {
    int * mergeArray = new int[length];
    int * mergeArray2 = new int[length];
    _mergeSort(arr, arr2, mergeArray,mergeArray2, 0, length - 1);
    delete[] mergeArray;
}


int main() {
    int N;
    cin>>N;
    int Ti,Bi;
    int end[N];
    int start[N];
    for(int i=0;i<N;i++)
    {
        cin >> Ti;
        start[i] = Ti;
        cin >> Bi;
        end[i] = Ti + Bi;
    }
    
    int *ptrEnd = &end[0];
    int *ptrStart = &start[0];
    mergeSort(ptrEnd, ptrStart, N);
    

    
    long long y = 1;
    long long ctr = 0;
    for(int i=1; i<N; i++)
    {
        if(end[ctr] <= start[i])
        {
            y++;
            ctr = i;
        }
    }
    if(N == 0)
    {
        cout << "0";
    }
    else
        cout << y;
    
    return 0;
}
