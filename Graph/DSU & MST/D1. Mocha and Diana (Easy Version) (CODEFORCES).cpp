#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e4 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int par1[N], cnt1[N], par2[N], cnt2[N], n;

void init(){
    iota(par1, par1 + n, 0);
    fill(cnt1, cnt1 + n, 1);
    iota(par2, par2 + n, 0);
    fill(cnt2, cnt2 + n, 1);
}

int findParent1(int u){
    if (u == par1[u]) return u;
    return par1[u] = findParent1(par1[u]);
}
int findParent2(int u){
    if (u == par2[u]) return u;
    return par2[u] = findParent2(par2[u]);
}

void join1(int u, int v){
    u = findParent1(u);
    v = findParent1(v);
    if(u != v){
        if(cnt1[u] > cnt1[v])
            swap(u, v);
        par1[u] = v;
        cnt1[v] += cnt1[u];
        }
}

void join2(int u, int v){
    u = findParent2(u);
    v = findParent2(v);
    if(u != v){
        if(cnt2[u] > cnt2[v])
            swap(u, v);
        par2[u] = v;
        cnt2[v] += cnt2[u];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m1, m2;
    cin>>n>>m1>>m2;
    init();
    for(int i = 0; i < m1; i++)
    {
        int u, v;
        cin>> u >> v;
        join1(--u, --v);
    }
    for(int i = 0; i < m2; i++)
    {
        int u, v;
        cin>> u >> v;
        join2(--u, --v);
    }

    int ans =0;
    vector<pair<int, int>> out;
    for(int i =0; i<n;++i) {
        for(int j =i+1; j<n;++j) {
            if ((findParent1(i) != findParent1(j)) && (findParent2(i) != findParent2(j))) {
                ans++;
                join1(i, j);
                join2(i, j);
                out.push_back({i, j});
            }


        }
    }
    cout<<ans<<endl;
    for(auto x:out)
        cout<<++x.first<<" "<<++x.second<<endl;

}



