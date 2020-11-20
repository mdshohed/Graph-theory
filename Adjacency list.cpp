
/*
input:
5 7
0 1
0 4
1 3
1 4
1 2
2 3
4 3
output:
adjacency list of vector 0: 1 4 
adjacency list of vector 1: 0 3 4 2 
adjacency list of vector 2: 1 3 
adjacency list of vector 3: 1 2 4 
adjacency list of vector 4: 0 1 3 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen( "in.txt", "r", stdin );
    freopen( "out.txt", "w", stdout );

    cin >> node >> edge;
    vector<int> adj[node];

    for (int i = 0; i<edge; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i<node; i++) {
        cout << "adjacency list of vector " << i << ": ";
        for (auto j: adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}


