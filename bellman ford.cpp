/*
problem: source distance find
Algorithm: bellman ford
input:
5 6
0 1 2
0 2 1
0 3 3
1 2 1
3 4 2
2 4 5
0
output:
source node: 0
0 --> 0 = 0
0 --> 1 = 1
0 --> 2 = 3
0 --> 3 = 5
0 --> 4 = 7

*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define EMPTY_VALUE -1
#define inf  1<<28
#define CLR(x,y) memset( x,y,sizeof(x))
#define FOR(x,n) for(int i = x; i<n; i++)
#define read(x) freopen(x, "r", stdin);
#define write(x) freopen( x, "w", stdout);

typedef long long ll;
typedef vector<int> v;
typedef pair<int,int> pii;
typedef map<string,int> mp;

const int MOD = 1e9+7;
const int mx = 1e4+9;

int fx[] = {+0, +0, +1, -1};
int fy[] = {+1, -1, +0, +0};

struct node {
    int u, v, w;
};

vector<node> adj;
int dis[mx];
int n, e,  source , dest;

int Bellman_ford(){

    for (int i = 0; i<n; i++) dis[i] = inf;
    dis[source] = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<adj.size(); j++){
            node tmp = adj[j];
            int u = tmp.u, v = tmp.v, w = tmp.w;
            if ( dis[v]>dis[u]+w && dis[u]!=inf) {
                dis[v] = dis[u]+w;
            }
        }
    }
    bool cycle=false;
    for (int j = 0; j<adj.size(); j++){
        node tmp = adj[j];
        int u = tmp.u, v = tmp.v, w = tmp.w;
        if ( dis[v]>dis[u]+w)  {
            cycle = true;
            break;
        }
    }

    if ( cycle ) cout << "negative cycle" << endl;
    else {
        for (int i = 0; i<n; i++){
            cout << source <<" --> " << i <<" = "<< dis[i] <<endl;
        }
    }
}

int main() {
    read("in.txt");
    write("out.txt");
    cin >> n >> e;
    for (int i = 0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        node tmp;
        tmp.u = u, tmp.v = v, tmp.w = w;
        adj.push_back(tmp);
    }
    cin >> source;
    Bellman_ford();
    return 0;
}
