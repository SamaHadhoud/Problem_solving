#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 1e5 + 4, mod = 1e9 + 7, inf = 0x3f3f3f;

int n, m;
vector<pair<int,int>> edg[N];
int dist[N];

void Dijkstra(int src){

    for(int i = 0; i < n; ++i)
        dist[i] = INT_MAX;
    dist[src] = 0;
    priority_queue<pair<int, int>> PQ;
    PQ.push({dist[src], src});
    while(!PQ.empty()){
        int u = PQ.top().second;
        int d = -PQ.top().first;
        PQ.pop();
        for(auto x:edg[u]){
            int v = x.second, c = x.first;
            int dd = d + c;
            if(dd < dist[v]){
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
    int t;
    cin>>t;

    while(t--){
        int src, dest;
        cin >> n >> m;
        cin >> src >> dest;
        for(int i=0; i<n;++i)
            edg[i].clear();
        for(int i = 0; i < m; ++i){
            int u,v, c;
            cin >> u >> v >> c;
            --u,--v;
            edg[u].push_back({c,v});
            edg[v].push_back({c,u});
        }
        Dijkstra(--src);
        if(dist[--dest] == INT_MAX)
            cout<<"NONE"<<endl;
        else
            cout<<dist[dest]<<endl;
    }
}



