#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

ll cost[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for ( int i = 1 ; i <= n ; ++i)
        for ( int j = 1 ; j <= n ; ++j)
            cin >> cost[i][j];
    int k ;
    cin >> k ;
    for(int h=0;h<k;++h) {
        int a , b , c ;
        cin >> a >> b >> c ;
        ll sum = 0 ;
        for ( int i = 1 ; i <= n ; ++i)
            for ( int j = 1 ; j <= n ; ++j)
            {
                cost[i][j] = min({ cost[i][j], cost[i][a]+ c +  cost[b][j], cost[i][b] + c +  cost[a][j]});
                sum +=  cost[i][j];
            }
        cout << sum / 2  << endl;
    }
}



