#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
vector<int> next;
vector<int> level;

struct flowedge{
    int u, v, cpp, flow = 0;
};

int addedge(int u, int v, int c, vector<vector<flowedge>> &adj ) {
    flowedge Forwaed = {v, adj[v].size(), 0, c};
    flowedge backward = {u, adj[u].size(), 0, c};
    adj[u].push_back(Forwaed);
    adj[v].push_back(backward);
}

bool bfs(int srcnode, int desnode, vector<vector<flowedge>> &adj) {
    fill(level.begin(),level.end(), -1);

    queue<int> q;
    q.push(srcnode);
    level[srcnode] = 0;
    while (!q.empty()) {
       
        int curnode = q.front(); q.pop();
        for (int i = 0; i<adj[curnode].size(); i++) {
            flowedge curedge = adj[curnode][i];
            int nextnode = curedge.v;

            if ( level[nextnode]==-1 && curedge.flow<curedge.cpp) {
                level[nextnode] = level[curnode]+1;
                q.push(nextnode);
            }
        }
    }
    return level[desnode] = -1;
}

int dfs(int curnode,int desnode,int curminflow, vector<vector<flowedge>> &adj) {
    if ( curnode==desnode) {
        return curminflow;
    }
    for (int i = 0; i<adj[curnode].size(); i++) {
        flowedge &e = adj[curnode][i];
        if ( level[e.u] == level[curnode]+1 && e.flow<e.cpp) {
            int nextflow = min( curminflow, e.cpp, e.flow);
            int dfsval = dfs(e.u, desnode, nextflow, adj);
        }
        if ( dfsval > 0) {
            e.flow += dfsval;
            adj[e.u][e.v].flow = dfsval;
            return dfsval;
        }
    }
    return 0;
}

int max_flow(int src,int dest,vector<vector<flowedge>> &adj) {
    int totalflow = 0;
    while ( bfs(src, dest, adj) ) {
         fill( next.begin(), next.end(), 0);
        int flow = dfs( src,dest,MAXVAL, adj );
        while (flow){
            totalflow = flow;
            flow = dfs(src, dest, MAXVAL , adj );
        }
    }
    return totalflow;
}

signed main() {
    freopen( "in.txt", "r", stdin );
    //ios::sync_with_stdio(false),cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    level.resize(n, 0);
    vector<vector<flowedge>> adj(n);
    for (int i = 0; i<n; i++ ) {
        int x, y, z;
        cin >> x >> y >> z;
        a--, b--;
        addedge(a, b, w, adj);
    }

    cout << max_flow(0, n-1, adj) << endl;
    return 0;

}
