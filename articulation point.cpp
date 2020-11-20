/*
problem: ...
algorithm: Articulation point
Input:
4 3
0 1
1 2
2 3
Output:
*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
vector<int> adj[mx];
int low[mx], parent[mx], d[mx];
bool visit[mx], ans[mx];
int t = 0;

int dfs(int u ) {
    visit[u] = true;
    int cnt = 0;
    d[u] = low[u] = ++t;
    for (auto v: adj[u] ) {
        if ( !visit[v]) {
            cnt++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if ( low[v]>=d[u] && parent[v]!=-1 ) ans[u] = true;
            if( parent[u]==-1 && cnt>1) ans[u] = true;
        }
        else if (parent[u]!=v) {
            low[u] = min(low[u], d[v]);
        }
    }
}

int main() {

    freopen( "in.txt", "r", stdin );
    int n, e;
    cin >> n >> e;
    for (int i = 0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(parent,-1,sizeof(parent));
    
    for (int i = 0; i<n; i++) {
        if (!visit[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i<n; i++) {
        if (ans[i]) {
            cout << i << " ";
        }
    }
}
