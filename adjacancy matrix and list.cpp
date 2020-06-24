#include <bits/stdc++.h>
using namespace std;

#define filein freopen("in.txt","r",stdin);
int node;
int edge;
int ara[100][100];

int main() {
    filein;
    int x , y;
    cin>>node >>edge;
    for ( int i = 0 ; i<edge; i++) {
        cin>>x >>y;
        ara[x][y] = 1;
        ara[y][x] = 1;
    }
    /// adjacancy matrix..
    for (int i = 0; i<node; i++) {
        for ( int j = 0; j<node; j++) {
            cout<<ara[i][j] << " ";
        }
        cout<<'\n';
    }
    cout<<endl;
    /// adjacancy list..
    for (int i = 0; i<node; i++) {
            cout<<i<<" -> ";
        for ( int j = 0; j<node; j++) {
            if ( ara[i][j] == 1) {
                cout<<j<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}
