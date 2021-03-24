#include <bits/stdc++.h>
using namespace std;

#define input(x) freopen(x, "r", stdin )
#define fastio() ios::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef pair<int,int> pii;

const int mx = 1e5+7;
vector<int> adj[mx];
int visit[mx];
int p[mx];

void bfs(int s, int destination) {

    memset(p, -1, sizeof(p));
    memset(visit,0, sizeof(visit));
    queue<int> q;
    q.push(s);
    visit[s] = 1;

    while (!q.empty()){
        int u = q.front(); q.pop();
        //cout << u << " ";
        for(auto v: adj[u]) {
            if (!visit[v]) {
                visit[v] = 1;
                q.push(v);
                p[v] = u;
            }
            if( v==destination) {
                vector<int> path;
                path.push_back(destination);
                for(int i = u; i!=-1; i= p[i]) {
                    path.push_back(i);
                }
                for (int i = 0; i<path.size(); i++){
                    cout << path[i] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin );

    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        //adj[y].push_back(x);
    }
    for (int i = 1; i<=n; i++) {
        cout << i << " :" << endl;
        bfs(i,n);
    }
}

