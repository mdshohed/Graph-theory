/*
problem: shortest path find
Algorithm: BFS
input:
8 9
0 1
0 3
1 2
3 4
3 7
4 5
4 6
5 6
6 7
2 6
output:
distance: 5
shortest path: 2 1 0 3 4 6
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4+9;

vector<int> adj[mx];
bool visit[mx];
vector<int> parent;
int dis[mx];
int node, edge, source, dest;
vector<int> path;

int bfs() {
    parent.assign(node,-1);
    queue<int> q;
    q.push(source);
    visit[source] = true;
    dis[source] = 0;

    while ( !q.empty()){
        int u = q.front();
        q.pop();
        for (auto v:adj[u]){
            if (!visit[v]) {
                q.push(v);
                dis[v] = dis[u]+1;
                visit[v] = true;
                parent[v] = u;
            }
        }
    }
    cout << "distance: " << dis[dest] << endl;
    path.push_back(dest);
    while( parent[dest]!=-1 ) {
        path.push_back(parent[dest]);
        dest = parent[dest];
    }
    cout << "shortest path: ";
    for (int i = path.size()-1; i>=0; i--) {
        cout << path[i] << " ";
    }
}

int main() {
    //freopen( "in.txt", "r", stdin );

    cin >> node >> edge;
    for (int i = 0; i<edge; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> source >> dest;
    bfs();
    return 0;
}
