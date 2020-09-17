#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector <int>& arr)
{
    int length=arr.size();
    int maxNumber = *max_element(arr.begin(), arr.end());

    int * countingArray = new int[maxNumber + 1];
    for (int i = 0; i < maxNumber + 1; i++) {
        countingArray[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        countingArray[arr[i]]++;
    }

    int sizeNew=0;
    for (int i = 0; i < maxNumber+1; i++) {
        if (countingArray[i] != 0) {

           arr[sizeNew]=i;
           sizeNew++;
        }
    }
    arr.resize(sizeNew);
    delete[] countingArray;
}

int game(vector <int>& arr,int different)
{
    int y=0;
    int tempDif=different;
    for(int i=arr.size()-1; i>=0; i--)
    {
        y++;
        if(arr[i-1]<=tempDif)
        {
            break;
        }
        tempDif+=different;
    }
    return y;
}

int main()
{
    int numMonsters;
    cin >> numMonsters;
    int dif;
    cin>>dif;
    vector<int> monster;
    int i = 0;
    int input;
    while (i++ != numMonsters) {
        cin >> input;
        monster.push_back(input);
    }
    countSort(monster);
    int a=game(monster,dif);
  //  printArray(monster);
    cout<<a;
    return 0;
}
