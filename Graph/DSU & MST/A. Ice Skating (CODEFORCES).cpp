#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e4 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int par[N], cnt[N], x[N], y[N], num_comps, n;

void init(){
    iota(par, par + n, 0);
    fill(cnt, cnt + n, 1);
    num_comps = n-1;
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
        --num_comps;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    init();
    for(int i = 0; i < n; i++)
    {
        cin>> x[i] >> y[i];
        for(int j = 0; j < i; j++)
        {
            if(x[i] == x[j] or y[i] == y[j])
                join(i, j);
        }
    }
    cout<<num_comps;
}
