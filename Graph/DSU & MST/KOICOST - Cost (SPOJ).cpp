#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e4 + 9, mod = 1e9 , inf = 0x3f3f3f;

int par[N], cnt[N];


int findParent(int u){
    if (u == par[u]) return u;
    return par[u] = findParent(par[u]);
}

void join(int u, int v){
    u = findParent(u);
    v = findParent(v);
    if(u != v){
        if(cnt[u] > cnt[v])
            swap(u, v);
        par[u] = v;
        cnt[v] += cnt[u];
    }
}

priority_queue<pair<ll, pair<int, int>>> edges;


ll kruskal(int n){
    iota(par, par + n, 0);
    fill(cnt, cnt + n, 1);

    ll ret = 0, c =0;
    while(!edges.empty()){
        auto e = edges.top();
        edges.pop();
        int u = findParent(e.second.first);
        int v = findParent(e.second.second);
        int k = e.first;
        if(u != v){
            c+= 1ll* cnt[u]*cnt[v];
            join(u, v);

        }
        ret = (ret+ ((c*k)%mod))%mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n>>m ;
    for(int i = 0; i < m; ++i){
        int u, v, k;
        cin >> u >> v >> k;
        edges.push({k, {--u, --v}});
    }
    cout << kruskal(n);
}
