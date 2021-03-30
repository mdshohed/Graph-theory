#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> readv(int n){vector<T>v(n);for(auto &i:v)cin>>i;return v;}
#ifdef auto v = readv<int>(n);
#endif
#define input(x)  freopen("in.txt","r",stdin)
#define debug(x) cerr << #x << " --> " << x << endl
#define make(x,y) make_pair(x,y)
#define ar array
#define ll long long
typedef pair<ll,ll> pi;

const int mxN = 500+7;
ll d[mxN][mxN];


int main() {
    //input( "in.txt");
    // ios_base::sync_with_stdio(false),cin.tie(nullptr);

    memset( d,0x3f, sizeof(d));
    int n, m, c;
    cin >> n >> m >> c;

    for ( int i = 0; i<m; i++ ){
        ll x, y,w;
        cin >> x >> y >> w;
        --x,--y;
        d[x][y] = min( d[x][y], w );
        d[y][x] = min( d[y][x], w );
    }
    for(int i = 0; i<n; i++ ) {
        d[i][i] = 0;
    }
    for (int k = 0; k<n; k++ ) {
        for  (int i = 0; i<n; i++ ) {
            for (int j = 0; j<n; j++ ) {
                d[i][j] = min( d[i][j], d[i][k]+d[k][j] );
            }
        }
    }

    for (int i = 0; i<c; i++) {
        int x, y;
        cin >> x >> y;
        --x,--y;

        cout << (d[x][y]>=1e18? -1: d[x][y]) << endl;
    }
}

