#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

void merge(ll * originalArray,ll *arr2, ll * mergeArray,ll * mergeArray2, ll start, ll mid, ll end) {
    ll left = start;
    ll right = mid + 1;

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

void _mergeSort(ll * originalArray,ll *arr2, ll * mergeArray,ll *mergeArray2, ll start, ll end) {
    if (start < end) {
        ll mid = (start + end) / 2;

        _mergeSort(originalArray,arr2, mergeArray,mergeArray2, start, mid);
        _mergeSort(originalArray,arr2, mergeArray,mergeArray2, mid + 1, end);

        merge(originalArray,arr2, mergeArray,mergeArray2, start, mid, end);
    }
}

void mergeSort(ll * arr, ll* arr2,ll length) {
    ll * mergeArray = new ll[length];
    ll * mergeArray2 = new ll[length];
    _mergeSort(arr, arr2, mergeArray,mergeArray2, 0, length - 1);
    delete[] mergeArray;
}


int main() {
    ll numTrucks;
    cin >> numTrucks;
    if(numTrucks == 0)
    {
        cout << numTrucks;
        return 0;
    }
    ll trucks[numTrucks];
    ll monsters[numTrucks];
    ll sumMonsters = 0;

    for(int i=0; i<numTrucks; i++)
    {
        cin >> trucks[i] >> monsters[i];
        sumMonsters += monsters[i]; 
    }
    ll *ptrTrucks = &trucks[0];
    ll *ptrMonsters = &monsters[0];
    mergeSort(ptrTrucks, ptrMonsters, numTrucks);
    ll end = numTrucks -1;
    ll tempSumLast = monsters[end];
    ll result = 0;
    for(int i= end-1; i>=0; i--)
    {
        if(trucks[i] < trucks[end])
        {
            
            if(2*tempSumLast <= sumMonsters)
            {
                result += (trucks[end] - trucks[i]) * tempSumLast;
                trucks[end] = trucks[i];
                tempSumLast += monsters[i]; 
            }
            else{
                result +=(trucks[end] - trucks[i]) * monsters[i];
                trucks[i] = trucks[end];
                tempSumLast += monsters[i];
            }
        }
        else
        {
            tempSumLast += monsters[i];
        }
    }
    cout << result << endl;
  
    return 0;
}
