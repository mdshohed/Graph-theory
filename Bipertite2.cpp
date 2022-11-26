#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7; 
vector<int> g[mx];
bool vis[mx];
int color[mx]; 

void dfs(int node, int col) {
    if(vis[node]) return; 
    vis[node] = 1; 
    color[node] = col;
    for(auto v: g[node]) {
        dfs( v, col^1 ); 
    }
    return; 
}

int main(){
#ifdef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    // freopen( "out.txt","w", stdout);
#endif 
    int n; 
    cin >> n; 
    std::vector<pair<int,int>> e;
    for(int i = 0; i<n; i++) {
        int x, y; 
        cin >> x >> y; 
        g[x].push_back(y);
        g[y].push_back(x);
        e.push_back({x,y}); 
    }
    dfs(1, 0);
    for(auto i:e) {
        if( color[i.first] == color[i.second]){
            cout << "Not Bipertite Graph" << endl;
            return 0;
        }
    }
    cout << "Bipertite Graph" << endl; 
    return 0;
}

/*Input: 
4
1 2
2 3
4 2
1 3
output: 
Not Bipertite Graph

Input: 
3
1 2
2 3
4 2
output: 
Bipertite Graph*/
