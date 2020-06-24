
#include<bits/stdc++.h>
using namespace std;
int node, edge;

#define white 1
#define gray 2
#define black 3
#define Max 1000

int adj[100][100];
int color[Max];
int level[Max];

void dfsvisit(int x) {
    color[x] = gray;
    for ( int i = 0; i<node; i++) {
        if ( adj[x][i] == 1) {
            if (color[i] == white) {
                dfsvisit(i);
            }
        }
    }
}
void dfs( int start ) {
    for ( int i = 0; i<node; i++) {
        color[i] = white;
    }
    for ( int i = 0; i<node; i++) {
        if (color[i] == white) {
            dfsvisit(i);
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    cin>>node>>edge;
    for ( int i = 0; i<edge; i++) {
        int x, y;
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    dfs(0);

    return 0;
}
