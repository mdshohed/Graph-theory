#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x.begin(),x.end())

vector<bool> vis; 
std::vector<std::vector<int>> adj;
void Dfs(int u) {
    if (vis[u]) return; 
    vis[u] = true; 
    for(int v: adj[u]) {
        Dfs(v); 
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n); 
    vis.resize(n); 
    for(int i = 0; i<m; i++) {
        int x, y; cin >> x >> y;
        x--,y--;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    int cnt = 0; 
    for(int i = 0; i<n; i++) {
        if (!vis[i]) {
            Dfs(i); 
            cnt++;
        }
    }
    cout << cnt << endl; 
}

int main() {
#ifndef Local
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    // freopen( "out.txt","w", stdout);
#endif  
    solve(); 
    return 0; 
}
