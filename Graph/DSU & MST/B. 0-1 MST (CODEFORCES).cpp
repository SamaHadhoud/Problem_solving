#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e4 + 9, mod = 1e9 , inf = 0x3f3f3f;

int n, par[N];
vector<int> adj[N];

void init(int n){
    iota(par, par + n, 0);
}


int findParent(int u){
    if (u == par[u]) return u;
    return par[u] = findParent(par[u]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, u, v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    set<int> st;
    for(int i = 1; i <= n; i++) par[i] = i, st.insert(i);
    for(int i = 1; i <= n; i++)
    {
        for(auto &x:adj[i]) st.erase(x);
        for(auto &x:st)
        {
            if(x != i)
            {
                par[findParent(x)] = findParent(i);
            }
        }
        st.clear();
        st.insert(i);
        for(auto &x:adj[i]) st.insert(x);
    }
    set<int> cnt;
    for(int i = 1; i <= n; i++)
        cnt.insert(findParent(i));
    cout<<cnt.size() - 1;
}
