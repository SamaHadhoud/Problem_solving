#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e2 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

ll cost[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, q;
    cin >> t;
    for(int tt =1; tt<=t; ++tt) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x;
                cin >> x;
                cost[i][j] = x;
            }
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);


        cin>>q;
        ll ans =0;
        for (int i = 0; i < q; ++i) {
            int u, v;
            cin>>u>>v;
            ans+= cost[u][v];
        }
        cout << "Case #"<<tt<<": "<<ans<< endl;
    }
}



