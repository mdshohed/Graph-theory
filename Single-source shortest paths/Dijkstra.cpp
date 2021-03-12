/*
problem: shortest path 
Algorithm: Dijkstra 
input:
5 6
0 1 2
0 2 1
0 3 3
1 2 1
3 4 2
2 4 5
0
output:
node: 0 Distance: 0
node: 1 Distance: 2
node: 2 Distance: 1
node: 3 Distance: 3
node: 4 Distance: 5
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int val, cost;
};

vector<node> adj[mx];
bool visit[mx];
int dis[mx];
int source;

class com{
public:
    bool operator()(node &a, node &b){
        return a.cost > b.cost;
    }
};

int dijkstra(){
    priority_queue<node,vector<node>,com> q;
    q.push( {source,0});
    //visit[source] = true;

    while( !q.empty()) {
        node tmp = q.top();
        q.pop();
        int u = tmp.val;
        int cost = tmp.cost;

        if (visit[u]) continue;
        dis[u] = cost;
        visit[u] = true;
        for (int i = 0; i<adj[u].size(); i++) {
            int v = adj[u][i].val;
            int v_cost = adj[u][i].cost;

            if ( !visit[v]) {
                q.push( {v, cost+v_cost});
            }
        }
    }
}

int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i= 0; i<edge; i++) {
        int u , v, w;
        cin >> u >> v >> w;
        adj[u].push_back( {v, w});
    }
    cout << "Inter source: " << endl;
    cin >> source;
    dijkstra();

    for (int i = 0; i<node; i++) {
        cout << "node: " << i << " Distance: " << dis[i] << endl;
    }
    cout << endl;
    return 0;
}
