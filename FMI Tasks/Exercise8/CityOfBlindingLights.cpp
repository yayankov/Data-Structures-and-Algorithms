#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

#define INF 1000000
using namespace std;

int dist[401][401];

int main() {
    int N, M, Q;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dist[i][j] = INF;
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) 
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == INF) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }
    
    return 0;
}
