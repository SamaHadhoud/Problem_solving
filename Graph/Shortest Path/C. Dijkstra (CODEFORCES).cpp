#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 1e5 + 4, mod = 1e9 + 7, inf = 0x3f3f3f;

int n, m;
vector<pair<int,int>> edg[N];
ll dist[N];

void Dijkstra(int src){

    for(int i = 0; i < n; ++i)
        dist[i] = 1e15;
    dist[src] = 0;
    priority_queue<pair<ll, int>> PQ;
    PQ.push({dist[src], src});
    while(!PQ.empty()){
        int u = PQ.top().second;
        ll d = -PQ.top().first;
        PQ.pop();
        for(auto x:edg[u]){
            ll v = x.second, c = x.first;
            ll dd = d + c;
            if(dd < dist[v]){
                dist[v] = dd;
                PQ.push({-dd, v});
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
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        edg[u].push_back({c, v});
        edg[v].push_back({c, u});
    }

    Dijkstra(0);
    if (dist[n-1] == 1e15)
        cout << -1;
    else {
        int cur = n-1;
        vector<int> path;
        while (cur != 0) {
            path.push_back(cur+1);
            ll dis = dist[cur];
            for (auto x : edg[cur]) {
                ll dis2 = dist[x.second] + x.first;
                if (dis == dis2) {
                    cur = x.second;
                    break;
                }
            }
        }
        path.push_back(1);
        while (path.size())
            cout << path.back() << " ", path.pop_back();
    }
}



