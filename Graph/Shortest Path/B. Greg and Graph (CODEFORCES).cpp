#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

ll cost[N][N], node[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for ( int i = 1 ; i <= n; ++i)
        for ( int j = 1 ; j <= n ; ++j)
            cin >> cost[i][j];

    for ( int i = n ; i >= 1 ; --i)
        cin >> node[i];

    for ( int idx = 1 ; idx <= n ; ++idx)
    {
        int k = node[idx];
        for ( int i = 1 ; i <= n ; ++i)
            for ( int j = 1 ; j <= n ; ++j)
                cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);


        for ( int idx2 = 1 ; idx2 <= idx ; ++idx2)
        {
            for ( int idx3 = 1 ; idx3 <= idx ; ++idx3)
            {
                int i = node[idx2]  , j = node[idx3];
                ans[idx] += cost[i][j];
            }
        }
    }
    for ( int i = n ; i > 0 ; --i)
        cout << ans[i] << endl;
}



