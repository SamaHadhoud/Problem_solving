#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 4, M = 2e5 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

struct edge{
    ll from, to, cost;
};

vector<edge> edges;

ll dist[N];
bool bellman(ll src){
    for(int i = 0; i < n; ++i)
        dist[i] = -1e15;
    dist[src] = 0;

    for(ll i = 0; i < n; ++i){
        for(ll e = 0; e < edges.size(); ++e){
            ll u = edges[e].from;
            ll v = edges[e].to;
            ll c = edges[e].cost;
            if(dist[u] + c > dist[v]){
                dist[v] = dist[u] + c;
                if((i == n - 1) && (v==n-1))
                    return true;
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll u, v, c;
        cin >> u >> v >> c;
        edges.push_back({--u, --v, c});
    }
    if(bellman(0))
        cout << "inf"<<endl;
    else
        cout << dist[n-1]<<endl;
}



