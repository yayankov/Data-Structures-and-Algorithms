#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct apple {
    int x,y;
};

bool isvalid(int i, int j, int R, int C) 
{ 
    return (i >= 1 && j >= 1 && i <= R && j <= C); 
} 

bool isdelim(apple temp) 
{ 
    return (temp.x == -1 && temp.y == -1); 
} 
int main() {

    int N,M,T;
    cin >> N >> M >> T;
    int arr[N+1][M+1] = {0};
    int a,b;
    queue<apple> Q;
    apple temp;
    int ctr = 0;
    int ans=0;
    while(cin >> a >> b)
    {
        arr[a][b] = 1;
        temp.x = a;
        temp.y = b;
        Q.push(temp);
        ctr++;
    }
    
    temp.x = -1; 
    temp.y = -1; 
    Q.push(temp); 
    
        while (!Q.empty() && T > ans) 
        { 
            bool flag = false; 
  
            while (!isdelim(Q.front()) )
            { 
                temp = Q.front(); 

                if (isvalid(temp.x+1, temp.y,N,M) && arr[temp.x+1][temp.y] == 0) 
                { 
                    if (!flag) ans++; flag = true; 
                    arr[temp.x+1][temp.y] = 1; 
                  //  cout << " Yees_1 " << arr[temp.x+1][temp.y] << endl;
                    temp.x++; 
                    Q.push(temp); 
                    temp.x--; 
                    ctr++;
                } 

                if (isvalid(temp.x-1, temp.y,N,M) && arr[temp.x-1][temp.y] == 0) { 
                    if (!flag) ans++; flag = true; 
                    arr[temp.x-1][temp.y] = 1; 
                 //   cout << " Yees_2 " << arr[temp.x-1][temp.y] << endl;
                    temp.x--; 
                    Q.push(temp);
                    temp.x++; 
                    ctr++;
                } 
 
                if (isvalid(temp.x, temp.y+1,N,M) && arr[temp.x][temp.y+1] == 0) { 
                    if (!flag) ans++; flag = true; 
                    arr[temp.x][temp.y+1] = 1; 
                   // cout << " Yees_3 " << arr[temp.x][temp.y+1] << endl;
                    temp.y++; 
                    Q.push(temp); 
                    temp.y--; 
                    ctr++;
                    
                } 

                if (isvalid(temp.x, temp.y-1,N,M) && arr[temp.x][temp.y-1] == 0) { 
                    if (!flag) ans++; flag = true; 
                    arr[temp.x][temp.y-1] = 1; 
                   // cout << " Yees_4 " << arr[temp.x][temp.y-1] << endl;
                    temp.y--; 
                    Q.push(temp); 
                    ctr++;
                } 

                Q.pop();
            } 
          //  cout << " tempCtr = " << ctr <<endl;
            Q.pop(); 

            if (!Q.empty()) { 
                temp.x = -1; 
                temp.y = -1; 
                Q.push(temp); 
            } 
            
        }
    
    cout << N*M - ctr;
    return 0;
}
