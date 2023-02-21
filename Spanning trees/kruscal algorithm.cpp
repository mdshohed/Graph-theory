#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5+7;

struct edge{
    int u, v, w;
    bool operator<(const edge& p) const {
        return w < p.w; 
    }
}; 

vector<edge> g;
int parent[mx];

int find(int n) {
    if(n==parent[n]) return n; 
    return parent[n] = find(parent[n]); 
}

int mst(int n) {
    sort(g.begin(), g.end());
    int sum = 0, cnt = 0; 
    for(int i = 0; i<g.size(); i++) {
        int x = find(g[i].u);
        int y = find(g[i].v);
        if( x!=y) {
            parent[y] = x;
            sum += g[i].w;  
            cnt++; 
        }
    }
    return sum;  
}

int main(){
#ifndef LOCAL
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
#else
    freopen( "in.txt", "r", stdin);
    // freopen( "out.txt","w", stdout);
#endif
    int tc, cases = 0; 
    cin >> tc;   
    while(tc--){
        for(int i = 0; i<mx; i++) g.clear();
        for(int i = 1; i<=mx; i++) parent[i] = i;
        int n, m, a;  
        cin >> n >> m >> a; 
        for(int i = 0; i<m; i++){
            int x, y, w;
            cin >> x >> y >> w; 
            if( w>=a ) continue;
            g.push_back({x,y,w});  
        }     
        int val = mst(n);  
        set<int> st;
        for(int i = 1; i<=n; i++) {
            st.insert(find(i)); 
        }
        int ans = val + (st.size()*a); 
        printf("Case %d: %d %d\n", ++cases,ans, st.size()); 

    }
    return 0;
}

