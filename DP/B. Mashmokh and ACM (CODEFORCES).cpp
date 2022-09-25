#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int n, k;
vector<vector<int>> dp ;


ll solve(int i, int l) {
    if (l == k) return 1;
    if (dp[i][l] != -1) return dp[i][l];
   ll ans =0;
   for(int j=i; j<=n;j+=i)
       ans = (ans+solve(j,l+1))%mod;
    return dp[i][l] = ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    dp = vector<vector<int>>(n+1, vector<int>(k+1,-1));

    cout<<solve(1, 0);


}



