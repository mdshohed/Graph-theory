/*
problem: ...
algorithm: MST (minimum spanning tree
Input:
9 13
0 1 4
0 7 8
1 7 11
7 8 7
7 6 1
8 2 2
1 2 8
2 5 4
2 3 7
3 5 14
3 4 9
5 4 10
8 6 6

Output:

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


const int MOD = 1e9+7;
const int mx = 1e4+9;

typedef long long ll;
typedef vector<int> v;
typedef pair<int,int> pii;
typedef map<string,int> mp;

int fx[] = {+0, +0, +1, -1};
int fy[] = {+1, -1, +0, +0};

vector<int> adj[mx], cost[mx];
vector<int> path;
bool visit[mx];
int n, e;

struct node {
    int u, v, w;
};

class com{
public:
    bool operator()(node &a, node &b){
        if (a.w > b.w) return true;
        else return false;
    }
};

int mst(){
    priority_queue<node,vector<node>,com> pq;
    visit[0] = true;
    for (int i = 0; i<adj[0].size(); i++) {
        node x;
        x.u  = 6; x.v = adj[0][i]; x.w = cost[0][i];
        pq.push(x);
    }
    int ans = 0, cnt = 0;
    while (!pq.empty()) {
        node x = pq.top();
        pq.pop();
        int u = x.u, v = x.v, w = x.w;
        if( visit[v]==false) {
            visit[v] = true;
            ans +=w;
            cout << u << " " << v << " " << w << endl;
            for(int i = 0; i<adj[v].size(); i++) {
                node x;
                x.u  = v; x.v = adj[v][i]; x.w = cost[v][i];
                pq.push(x);
            }
            cnt++;
        }
        if (cnt==n-1) break;
    }
    cout << endl;
    return ans;
}

int main(){

    read( "in.txt");
    cin >> n >> e;
    for (int i = 0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int x = mst();
    cout << x << endl;
    return 0;
}

