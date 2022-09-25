#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

int head[N], to[M], cost[M], nxt[M], ne;

void init(){
    memset(head, -1, sizeof head);
    ne = 0;
}

void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBiEdge(int a, int b, int c){
    addEdge(a, b, c);
    addEdge(b, a, c);
}


ll dist[N];
bool inQ[N];
bool bellmanOptimized(ll src){
    memset(inQ, 0, sizeof inQ);
    for(int i = 0; i < n; ++i)
        dist[i] = INT_MAX;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    inQ[src] = 1;
    for(int i = 0; i < n; ++i){
        int s = q.size();
        while(s--){
            int u = q.front();
            q.pop();
            inQ[u] = 0;
            for(int e = head[u]; ~e; e = nxt[e]){
                int v = to[e], c = cost[e];
                if(dist[u] + c < dist[v]){
                    dist[v] = dist[u] + c;
                    if(!inQ[v]){
                        q.push(v);
                        inQ[v] = 1;
                    }
                }
            }
        }
        if(i == n - 1 && q.size()) return true;
        if(q.empty()) break;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin >> n >> m;
        init();
        for(int i = 0; i < m; ++i){
            int u, v, c;
            cin >> u >> v >> c;
            addEdge(u, v, c);
        }
        if(bellmanOptimized(0)){
            cout << "possible\n";
        }
        else{
            cout << "not possible\n";
        }
    }
}



