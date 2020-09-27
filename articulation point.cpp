/*
problem: ...
algorithm: articulation point
Input:
4 3
0 1
1 2
2 3
Output:

*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define EMPTY_VALUE -1
#define inf  1<<28
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)
#define read(x) freopen(x, "r", stdin);
#define write(x) freopen( x, "w", stdout);


const int MOD = 1e9+7;
const int mx = 1e4+9;

typedef long long ll;
typedef vector<int> v;
typedef pair<int,int> pii;
//typedef map<string,int> mp;

int fx[] = {+0, +0, +1, -1};
int fy[] = {+1, -1, +0, +0};

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
    read( "in.txt");
    int n, e;
    cin >> n >> e;
    for (int i = 0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    CLR(parent, -1);
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
