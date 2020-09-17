#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack <int> trees;
    int numTrees;
    cin >> numTrees;
    
    int maxVisible = 0;
    int * arr= new int[numTrees];
    int position = numTrees
    
    for(int i=0; i<numTrees; i++)
        cin>>arr[i];
        
    for(int j=numTrees-1; j>=0; j--)
    {
        if(trees.empty() || arr[j] < trees.top()) {
            trees.push(arr[j]);
        }
        else {
            while(!trees.empty() && arr[j] >= trees.top()) {
                trees.pop();
            }
            trees.push(arr[j]);
        } 
        if(!trees.empty() && maxVisible <= trees.size())
        {
            maxVisible = trees.size();
            position = j;
        }
    }
    
    cout << position;
    return 0;
}
