#include <bits/stdc++.h>
using namespace std;
#define filein freopen("in.txt","r",stdin);
#define white 1
#define gray 2
#define black 3

int adj[100][100];
int color[100];
int parent[100];
int dis[100];
int node, edge;

int bfs( int root) {
    for ( int i = 0; i<node; i++){
        color[i] = white;
        dis[i] = INT_MIN;
        parent[i] = -1;
    }
    dis[root] = 0;
    parent[root] = -1;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int x;
        x = q.front();
        q.pop();
        color[x] = gray;
        cout<<x<<" ";
        for ( int i = 0; i<node; i++) {
            if ( adj[x][i] == 1) {
                if ( color[i] == white) {
                    dis[i] = dis[x] + 1;
                    parent[i] = x;
                    q.push(i);
                }
            }
        }
        color[x] = black;
    }
}
int main() {
    filein;
    int x, y;
    cin>> node >>edge;
    for ( int i = 0; i<edge; i++) {
        cin>>x >>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    bfs(1);
    cout<<parent[5]<<endl;
    cout<<dis[3]<<'\n';
    return 0;
}
