
/*
5 7
0 1
0 4
1 3
1 4
1 2
2 3
4 3
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen( "in.txt", "r", stdin );

    int node, edge;
    cin >> node >> edge;
    vector<int> adj[node];

    for (int i = 0; i<edge; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i<node; i++) {
        cout << "adjacency list "  << i << ": " ;
        for (auto j: adj[i] ) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}


