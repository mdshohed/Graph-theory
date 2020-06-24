#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
vector<int> adj[mx];
bool visited[mx];
vector<int> path;

void dfs(int v) {
    visited[v] = true;
    path.push_back(v);
    for(int u: adj[v]){
        if ( !visited[u])
            dfs(u);
    }
}

int main() {

    //freopen( "in.txt", "r", stdin);
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i<edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(5);
    for (int i = 0; i<nodes; i++) {
        if ( visited[i] == true) {
            cout << "Node " << i << " is visited" << '\n';
        }
        else {
            cout << "Node " << i << "is not visited" << '\n';
        }
    }
    for (int i  = 0; i<nodes; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}
