/*
input:
5 6
5 0
4 0
2 3
3 1
4 1
5 2

output:

5 4 2 3 1 0

*/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5+7;

vector<int> adj[mx];
bool visit[mx];
int x = 0;
int start_t[mx], end_t[mx], cnt = 0;
int color[mx];
stack<int> st;

void dfs(int u ) {

    if(visit[u]) return;
    visit[u] = true;
    color[u] = 1;
    start_t[u] = ++cnt;

    for (auto v: adj[u]) {
        dfs(v);
    }
    color[u] = 2;
    end_t[u] = ++cnt;
    //cout << u << " ";
    st.push(u);
}

int main(){
    freopen( "in.txt", "r", stdin );
    freopen( "out.txt", "w", stdout );
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i<edge; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 0; i<=node; i++) dfs(i);
    cout << endl;

    while( !st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
