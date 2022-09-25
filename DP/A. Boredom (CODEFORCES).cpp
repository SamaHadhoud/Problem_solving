#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int freq[N], n, mn = INT_MAX, mx=0;
ll dp [N];

ll solve(int i) {
    if (i > mx) return 0;
    if (dp[i]!= -1) return dp[i];
    ll op1 = solve(i+1);
    ll op2 = solve(i+2)+ (ll)i*freq[i];
    return dp[i] = max({op1, op2});
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    fill(dp, dp+N,-1);
    for(int i =0 ; i<n ;++i ){
        int x;
        cin>>x;
        freq[x]++;
        mn= min(x, mn);
        mx = max(mx, x);
    }
    cout<<solve(mn);


}



