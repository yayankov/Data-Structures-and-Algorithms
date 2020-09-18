#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<int, int> pocket;
     int n;
    cin >> n;
    int input1;
    int input2;
    int newKey = 0;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0; i<n-1; i++)
    {
        cin>>input1;
        arr1.push_back(input1);
    }
    for(int i=0; i<n-1; i++)
    {
        cin>>input2;
        arr2.push_back(input2);
    }
    for(int i=0; i<n-1; i++)
    {
        if(pocket.find(arr1[i]) == pocket.end())
        {
            pocket.insert(pair<int, int>(arr1[i], 0));
        }
        pocket[arr1[i]]++;
        
        if(pocket.find(arr2[i]) == pocket.end())
        {
            newKey++;
        }
        else {
            pocket[arr2[i]]--;
            if(pocket[arr2[i]] == 0)
                pocket.erase(arr2[i]);
        }
    }
    cout << newKey;
    return 0;
}
