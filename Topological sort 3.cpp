#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;
vector<int> adj[mx];
vector<bool> visit;
vector<int> ans;

void dfs(int u) {
    if (visit[u]) return;
    visit[u] = 1;
    for (auto v: adj[u]) {
        dfs(v);
    }
    ans.push_back(u);
}

void topological_sort(int n) {
    visit.assign(n,false);
    ans.clear();
    for (int i = 0; i<n; i++) {
        if (!visit[i]) dfs(i);
    }
    reverse(ans.begin(),ans.end());
}

int main() {
    //freopen( "in.txt", "r", stdin );
    //ios::sync_with_stdio(false),cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++ ) {
        int x, y;
        //x--,y--;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    topological_sort(n);
    for (int i = 0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;

}
