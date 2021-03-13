#include <bits/stdc++.h>
using namespace std;

int fx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int fy[] = {1, 0, -1, 0, -1, 1, 1, -1};

const int mx = 100;
int ara[mx][mx];
int ans = 0, n, m;

void dfs(int x, int y) {
    if ( 1>x || x>n ) return;
    if ( 1>y || y>m ) return;
    if ( !ara[x][y] ) return;

    ara[x][y] = 0;
    if ( x==n && y==m) {
        ans = 1; return;
    }
    for (int i = 0; i<4; i++) {
        int dx = fx[i]+x;
        int dy = fy[i]+y;
        dfs(dx, dy);
    }
}

int32_t main() {
  
    cin >> n >> m;
    for (int i = 1; i<=n; i++ ) {
        for (int j = 1; j<=m; j++ ) {
            cin >> ara[i][j];
        }
    }

    dfs(1,1);
    if ( ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
