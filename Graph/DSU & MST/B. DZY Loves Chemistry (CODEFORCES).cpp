#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e4 + 9, mod = 1e9 , inf = 0x3f3f3f;

int par[N], cnt[N];

void init(int n){
    iota(par, par + n, 0);
    fill(cnt, cnt + n, 1);
}


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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n>>m ;
    init(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        if(findParent(u) != findParent(v)){
            join(u, v);
        }
    }
    ll ans =1;
    for(int i = 0; i < n; ++i){
       if(par[i] == i){
       int x= --cnt[i];
       while(x--)
           ans*=2;}
    }

    cout << ans;
}
