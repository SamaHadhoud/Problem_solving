#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 4, M = 1e5 + 4, mod = 1e9 + 7, inf = 0x3f3f3f;

int n, m;
vector<pair<ll,int>> edg[N];
ll dist[N], c[N];

void Dijkstra(){

    priority_queue<pair<ll, int>> PQ;
    for ( int i = 0 ; i < n ; ++i) {
        dist[i] = c[i];
        PQ.push(make_pair(-c[i], i));
    }
    while(!PQ.empty()){
        int u = PQ.top().second;
        ll d = -PQ.top().first;
        PQ.pop();
        if ( dist[u] != d)
            continue;
        for(auto x:edg[u]){
            if(d + (x.first<<1) < dist[x.second]){
                dist[x.second] = d + (x.first<<1);
                PQ.push(make_pair(- (d + (x.first<<1)), x.second));
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u, --v;
        edg[u].push_back({c, v});
        edg[v].push_back({c, u});
    }
    for (int i = 0; i < n; ++i)
        cin>>c[i];
    Dijkstra();
    for (int i = 0; i < n; ++i)
        cout<<dist[i]<<" ";

}



