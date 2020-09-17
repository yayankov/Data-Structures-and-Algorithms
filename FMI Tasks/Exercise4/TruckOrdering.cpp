#include<stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    stack <long long> street;
    long long num;
    cin >> num;
    long long n;
    long long input;
    long long ctr;
    for(int i=0; i<num; i++)
    {
        ctr = 1;
        cin >> n;
        for(int j=0; j<n; j++)
        {
            cin >> input;
            street.push(input);
            if(street.top() == ctr)
            {
                street.pop();
                ctr++; 
                while(!street.empty() && street.top() == ctr)
                {
                    street.pop();
                    ctr++;
                }  
            }
        }
        if(street.empty()) {
            cout << "yes" << endl;
        } 
        else {
            cout<<"no"<<endl;
        }
        while(!street.empty()) {
            street.pop();
        }
    }
    return 0;
}
