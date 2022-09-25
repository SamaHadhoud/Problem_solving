#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e2 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

ll cost[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    m=1;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            string x;
            cin>>x;
            if(x[0] == 'x')
                cost[i][j] = cost[j][i] = inf;
            else
                cost[i][j] = cost[j][i]= atoi(x.c_str());
        }
        m++;
    }

    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);


    ll ans = 0;
    for(int i =1; i<n;++i){
        ans = max(ans, cost[1][i]);
    }
    cout<<ans<<endl;
}



