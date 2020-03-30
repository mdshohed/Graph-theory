#include<bits/stdc++.h>
using namespace std;
int node, edge;
int t = 1;

#define white 1
#define gray 2
#define black 3
#define Max 1000

int adj[100][100];
int color[Max];
int stime[100];
int ft[100];

void dfsvisit(int x) {
    color[x] = gray;
    stime[x] = t;
    t++;
    for ( int i = 0; i<node; i++) {
        if ( adj[x][i] == 1) {
            if ( color[x] == white) {
                dfsvisit(i);
            }
        }
    }
    color[x] = black;
    ft[x] = t;
    ++t;
}
void dfs(int x) {
    for ( int i = 0; i<node; i++) {
        color[i] = white;
    }
    for( int i = 0; i<node; i++) {
        if ( color[i] == white) {
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
        //adj[y][x] = 1;
    }
    dfs(0);
    for (int i = 0; i<node; i++) {
        cout<<"Nod: " << (char)('A' + i) << " "<<stime[i] << " "<<ft[i]<<endl;
    }
    return 0;
}
