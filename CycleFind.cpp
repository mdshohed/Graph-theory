#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x.begin(),x.end())

vector<bool> vis; 
std::vector<std::vector<int>> adj;
bool Dfs(int u, int par) {
    vis[u] = true;
    bool isLoopExists =false; 
    for(int v: adj[u]) {
        if(vis[v] && v==par) continue;
        if (vis[v]) return true; 
        isLoopExists |= Dfs(v, u); 
    }
    return isLoopExists;  
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n); 
    vis.resize(n); 
    adj.clear(); 
    vis.clear(); 
    for(int i = 0; i<m; i++) {
        int x, y; cin >> x >> y;
        x--,y--;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    int ans = 0; 
    for(int i = 0; i<n; i++) {
        if (!vis[i]) {
            ans |= Dfs(i,-1); 
            if(ans) break;  
        }
    }
    cout << (ans?"Cycle found":"Cycle not found") << endl; 
}

int main() {
#ifdef Local
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    // freopen( "out.txt","w", stdout);
#endif  
    int t; 
    cin >> t; 
    while (t--) solve(); 
    return 0; 
}

/*
2
8 5
1 2
2 3
2 4
3 5
6 7

8 6
1 2
2 3
2 4
3 5
6 7
1 5
*/

