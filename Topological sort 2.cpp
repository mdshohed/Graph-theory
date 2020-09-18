#include<bits/stdc++.h>
using namespace std;

#define white 1
#define gray 2
#define black 3
#define Max 10000

int adj[100][100], color[Max],startingtime[Max],finisingtim[Max];
int node, edge, Time = 1;
stack<int> s;

void dfsvisit( int x) {
    startingtime[Time] = Time++;
    color[x] = gray;
    for ( int i = 0; i<node; i++) {
        if ( adj[x][i] == 1 ){
            if ( color[i] == white) {
                dfsvisit(i);
            }
        }
    }
    color[x] = black;
    finisingtim[x] = Time++;
    s.push(x);
}

void dfs () {
    for ( int i = 0; i<node; i++) {
        color[i] = white;
    }
    for ( int i = 0; i<node; i++) {
        if (color[i] == white) {
            dfsvisit(i);
        }
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    cin>>node>>edge;
    for ( int i  = 0; i<edge; i++) {
        int x, y;
        cin>>x>>y;
        adj[x][y] = 1;
    }
    dfs();
    cout<<"after topological sort the area element"<<endl;
    while( !s.empty()){
        cout<< s.top()<< " ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
