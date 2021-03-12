
#include<bits/stdc++.h>
using namespace std;

struct node {
    int v, w;
};
const int mx = 1e5+7;
vector<node> adj[mx];
int visit[mx];
int parent[mx];
int dis[mx];

class cmp {
public:
    bool operator()( node& a, node& b) {
        return a.w>b.w;
    }
};

int dijkstra(int source,int n) {
    memset( parent,-1, sizeof(parent));
    fill( dis,dis+mx,INT_MAX);

    priority_queue<node,vector<node>,cmp> q;
    q.push( {source,0});
    dis[source] = 0;

    while (!q.empty()) {
        node tmp = q.top(); q.pop();
        int u = tmp.v;
        int cost = tmp.w;

        if (n==u) return true;

        visit[u] = true;

        for (auto i: adj[u]) {
            int v = i.v, w = i.w;
            if ( !visit[v] && dis[u]+w<dis[v]) {
                dis[v] = dis[u] + w;
                parent[v] = u;
                q.push( {v, dis[v]});
            }
        }
    }
    return false;
}

int main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back( {x,w});
    }
    dijkstra(1,n);
    stack<int> ans;
    ans.push(n);
    while ( parent[n]!=-1 ) {
        n = parent[n];
        ans.push(n);
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
    
}

