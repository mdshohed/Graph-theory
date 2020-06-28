
#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
    bool operator<(const edge& p) const {
        return w < p.w;
    }
};

vector<edge> e;
int parent[1000];

int find(int v) {
    return (parent[v] == v) ? v : find( parent[v]);
}

int mst(int  n) {

    sort( e.begin(), e.end());
    for (int i = 0; i<n; i++) {
        parent[i] = i;
    }
    int cnt = 0, sum = 0;
    for (int i = 0; i<e.size(); i++) {
        int u = find(e[i].u);
        int v = find( e[i].v);
        if ( u != v) {
            parent[v] = u;
            cnt++;
            sum +=e[i].w;
            if ( cnt == n-1 ) break;
        }
    }
    return sum;
}

int main() {

    //freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edge get;
        get.u = x;
        get.v = y;
        get.w = z;
        e.push_back(get);
        // another way -> e.push_back( {x,y,x});
    }
    cout << mst(n) << '\n';
    return 0;
}
