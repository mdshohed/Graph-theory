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

int adj[mx][mx];
int n, e;

int main() {

    read( "in.txt");
    cin >> n >> e;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if ( i==j) adj[i][j] = 0;
            else adj[i][j]= inf;
        }
    }
    for (int i = 0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for (int k= 0; k<n; k++) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                if ( adj[i][j] > adj[i][k]+adj[k][j]){
                    //adj[i][j] = min( adj[i][j], adj[i][k]+adj[k][j] );
                    adj[i][j] = adj[i][k]+adj[k][j];
                }

            }
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j= 0; j<n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
