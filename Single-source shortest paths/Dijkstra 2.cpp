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
typedef long long ll;
typedef pair<ll,ll> pi;

const int mxN = 1e5+7;
vector<pi> adj[mxN];
ll d[mxN];

void dijktra(int s ) {

    priority_queue<pi,vector<pi>,greater<pi>> pq;
    memset( d,0x3f, sizeof(d));
    pq.push ( {0,1} );
    d[1] = 0;

    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();

        if ( d[u.second]>u.first ) continue;

        for(auto i:adj[u.second] ) {
            int w = i.first, v = i.second;
            if ( d[u.second]+w < d[v] ) {
                d[v] = d[u.second]+w;
                pq.push( {d[v],v});
            }
        }
    }
}

int main() {
    //input( "in.txt");
    // ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0,x, y, z; i<m; i++ ) {
        cin >> x >> y >> z;
        adj[x].push_back( {z,y});
        adj[y].push_back( {z,x});
    }
    dijktra(1);
    for (int i = 1; i<=n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
}

