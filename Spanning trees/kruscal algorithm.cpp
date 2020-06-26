#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
struct edge{
    int u, v, weight;
    bool operator<(edge const& p) {
        return weight < p.weight;
    }
};

int pr[mx];
vector<edge> e;

int find(int r ) {
    return ( pr[r] == r ) ? r : find(pr[r]);
}

int mst(int n ) {

    sort( e.begin(), e.end());
    for (int i = 0; i<n; i++) {
        pr[i] = i;
    }
    int cnt = 0, s = 0;
    for (int i = 0; i< e.size(); i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if ( u != v ) {
            pr[u] = v;
            cnt++;
            s += e[i].weight;
            if ( cnt == n - 1) {
                break;
            }
        }
    }
    return s;
}

int main() {

    //freopen( "in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge get;
        get.u = x;
        get.v = y;
        get.weight = z;
        e.push_back(get);
    }
    cout << mst(n) << '\n';
    return 0;
}
