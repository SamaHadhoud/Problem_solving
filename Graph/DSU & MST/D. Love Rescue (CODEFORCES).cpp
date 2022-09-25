#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e4 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int par[26], cnt[26];


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

vector<pair<int, int>> edges;


ll kruskal(int n){
    iota(par, par + 26, 0);
    fill(cnt, cnt + 26, 1);

    int ret = 0;
    for(auto e :edges){
        int u = e.first;
        int v = e.second;
        if(findParent(u) != findParent(v)){
            join(u, v);
            ret++;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string a,b;
    cin >> n >> a>> b;
    for(int i = 0; i < n; ++i){
        int u = a[i]-'a';
        int v = b[i]-'a';
        edges.push_back({u, v});
    }
    cout << kruskal(n)<<endl;
    for(int i =0; i<26; ++i){
        if(findParent(i) != i)
            cout<<char(i+'a')<<" "<<char(findParent(i)+'a')<<endl;

    }


}
