/*
input:
5 5
1 0
0 2
2 1
0 3
3 4
output:
graph 1: 0 1 2 
graph 2: 3 
graph 3: 4 

*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
vector<int> adj[mx], rev_adj[mx];
vector<int> q;
bool visit[mx];
int start_t[mx], end_t[mx];
int tc = 0;
int n, e;
int x = 0;

void dfs(int u) {
    if (visit[u]) return;
    visit[u] = 1;
    start_t[u] = ++tc;
    for (auto v: adj[u] ) {
        dfs(v);
    }

    end_t[u] = ++tc;
    q.push_back(u);
}

void dfs2(int u) {
    if (!visit[u]) return;
    visit[u] = false;
    cout << u << " ";
    for (auto v:rev_adj[u]) {
        dfs2(v);
    }
}

int main() {
    //freopen( "in.txt", "r", stdin );
    //freopen( "out.txt", "w", stdout);
    cin >> n >> e;
    for (int i = 0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for (int i = 0; i<n; i++) dfs(i);

    for (int i = q.size()-1; i>=0; i--) {
        int u = q[i];
        if (visit[u]) {
            cout << "graph " << ++x << ": ";
            dfs2(u);
            cout << endl;
        }
    }
    return 0;
}
