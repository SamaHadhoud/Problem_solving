#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int n;
vector<vector<int>> dp ;
vector<int> v;
vector<int> h;


ll solve(int i, bool lastR) {
    if (i > n-1) return 0;
    if (i == n-1) return 1;
    if (dp[i][lastR] != -1) return dp[i][lastR];
    int op1, op2, op3;
    op1 = solve(i+1, 0);
    if(i==0 || (lastR && (v[i]-h[i])>(v[i-1]+h[i-1])) || (!lastR && (v[i]-h[i])>v[i-1]))
        op2 = solve(i+1, 0)+1;
    else
        op2 =0;
    if(i==n-1 || ((v[i]+h[i])<v[i+1]))
        op3 = solve(i+1, 1)+1;
    else
        op3 =0;
    return dp[i][lastR] = max({op1, op2, op3});
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    dp = vector<vector<int>>(n, vector<int>(2,-1));
    for(int i =0 ; i<n ;++i ){
        int x, y;
        cin>>x>>y;
        v.push_back(x);
        h.push_back(y);
    }
    cout<<solve(0, 0);


}



