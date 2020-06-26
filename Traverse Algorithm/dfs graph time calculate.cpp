#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
vector<int> adj[mx];
vector<int> color;
vector<int> time_in, time_out;
int time_start  = 0;

void dfs(int v) {
    time_in[v] = time_start++;
    color[v] = 1;
    for (int u: adj[v]) {
        if ( color[u] == 0) {
            dfs(u);
        }
    }
    color[v] = 2;
    time_out[v] = time_start++;
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
    dfs(1);

    for (int i = 0; i<nodes; i++) {

    }
    return 0;
}
