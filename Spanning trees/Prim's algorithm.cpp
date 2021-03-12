/*
problem: ...
algorithm: prim algorithm (minimum spanning tree)
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
41

*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
typedef long long ll;
typedef pair<ll, int> pi;
bool marked[MAX];
vector <pi> adj[MAX];

ll prim(int x){
    priority_queue<pi, vector<pi>, greater<pi> > Q;

    ll minimumCost = 0;
    Q.push(make_pair(0, x));

    while(!Q.empty()){
        pi p = Q.top();
        Q.pop();
        x = p.second;

        if(marked[x]) continue;

        minimumCost += p.first;
        marked[x] = true;

        for(auto i :adj[x] ){
            int y = i.second;
            if(!marked[y]){
                Q.push(i);
            }
        }
    }
    return minimumCost;
}

int main(){
    freopen( "in.txt", "r", stdin );

    int nodes, edges, x, y;
    ll weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i){
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair( weight,y));
        adj[y].push_back(make_pair( weight, x));
    }
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}


