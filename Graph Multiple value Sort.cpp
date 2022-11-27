#include <bits/stdc++.h>

using namespace std;

struct edge{
    int u, v, w; 
    bool operator<(const edge &p) const{
        return v < p.v;
    }
};
std::vector<edge> g;

int main(){
    int n, m; 
    cin >> n >> m; 
    for(int i = 0; i<m; i++) {
        int u, v, w; 
        cin >> u >> v >> w; 
        edge e = {u, v, w};
        g.push_back(e);
    }
    sort( g.begin(), g.end()); 
    for(auto i: g) {
        cout << i.u << " " << i.v << " " << i.w << endl;
    }
    cout << endl;
    return 0;
}

