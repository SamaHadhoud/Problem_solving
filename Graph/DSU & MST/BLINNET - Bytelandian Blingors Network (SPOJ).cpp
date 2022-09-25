#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e4 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

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

    ll ret = 0;
    while(!edges.empty()){
        auto e = edges.top();
        edges.pop();
        int u = e.second.first;
        int v = e.second.second;
        ll k = -e.first;
        if(findParent(u) != findParent(v)){
            join(u, v);
            ret += k;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m,t;
    cin >> t;
    while(t--){
        cin>>n;
    for(int i = 0; i < n; ++i){
        string s;
        cin>>s>>m;
        while(m--) {
            int v, k;
            cin >> v >> k;
            edges.push({-k, {i, --v}});
        }
    }
    cout << kruskal(n)<<endl;
}}
