#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int n, k, mx=0;
vector<ll> dp ;


ll solve(int i) {
    if ( i == 0) return dp[i]=1;
    if (dp[i] != -1) return dp[i];
    ll op1 = solve(i-1);
    ll op2;
    if(i<k)
        op2 =0;
    else
        op2 = solve(i-k);
    return dp[i] = (op1+op2)%mod;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;

    vector<int> a;
    vector<int> b;

    for(int i =0; i<n;++i){
        int x, y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
        mx = max(mx, y);
    }
    dp = vector<ll>(mx+1, -1);
    solve(mx);
    for(int i =1; i<=mx;++i){
        dp[i]+=dp[i-1];
    }
    for(int i =0; i<n;++i){
        cout<<(dp[b[i]]-dp[a[i]-1])%mod<<endl;

    }

}



