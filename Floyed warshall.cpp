#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4+9;

int adj[mx][mx];
int n, e;

int main() {
    //freopen( "in.txt", "r", stdin);
    
    cin >> n >> e;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if ( i==j) adj[i][j] = 0;
            else adj[i][j]= INT_MAX;
        }
    }
    for (int i = 0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for (int k= 0; k<n; k++) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if ( adj[i][j] > adj[i][k]+adj[k][j]){
                    //adj[i][j] = min( adj[i][j], adj[i][k]+adj[k][j] );
                    adj[i][j] = adj[i][k]+adj[k][j];
                }

            }
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j= 0; j<n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
