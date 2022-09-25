#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 1e5 + 4, mod = 1e9 + 7, inf = 0x3f3f3f;

int n, m,k, ans, l;
vector<pair<pair<int,int>,int>> edg[N];
map <int, ll> mp;
ll dist[N];
bool done[N];

void Dijkstra(int src){

    for(int i = 0; i < n; ++i)
        dist[i] = LONG_LONG_MAX;
    dist[src] = 0;
    priority_queue<pair<ll, int>> PQ;
    PQ.push({dist[src], src});
    while(!PQ.empty()){
        int u = PQ.top().second;
        ll d = -PQ.top().first;
        PQ.pop();
        if(d != dist[u]) continue;
        for(auto x:edg[u]) {
            int v = x.first.second, c = x.first.first;
            ll dd = d + c;
            if (dd == dist[v]){
                if ((!x.second) && (dd <= mp[v]) && mp[v]) {
                    if (done[v] == 0) {
                        done[v] = 1,l++;
                        if (l == mp.size())
                            break;
                    }
                }
            }
            if(dd < dist[v]){
                if((!x.second)&& (dd<=mp[v]) && mp[v]) {
                    if (done[v] == 0) {
                        done[v] = 1, l++;
                        if (l == mp.size())
                            break;
                    }
                }
                dist[v] = dd;
                PQ.push({-dd, v});
            }
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m>> k;
    for(int i = 0; i < m; ++i){
        int u,v, c;
        cin >> u >> v >> c;
        --u,--v;
        edg[u].push_back({{c,v},0});
        edg[v].push_back({{c,u}, 0});
    }
    for(int i = 0; i < k; ++i){
        int s, y;
        cin>>s>>y;
        s--;
        if(mp[s]){
            if(mp[s]>y)
                mp[s]=y;
            ans++;
        }
        else
            mp[s]=y;
    }
    for(auto x:mp){
        int s = x.first;
        int y = x.second;
        edg[0].push_back({{y,s},1});
        edg[s].push_back({{y,0},1});
    }
    Dijkstra(0);
    for(auto x:mp)
        if(done[x.first]) ans++;
    cout<<ans;
}




