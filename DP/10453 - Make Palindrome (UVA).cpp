#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int n;
string s;
vector<vector<int>> dp ;


ll solve(int i, int j) {
    if(i>j) return 0;
    if (s[i] == s[j]) return solve(i+1, j-1);
    if (dp[i][j] != -1) return dp[i][j];
    ll op1 = solve(i+1, j)+1;
    ll op2 = solve(i, j-1)+1;
    return dp[i][j] = min(op1, op2);
}

void printt(int i, int j) {
    if(i>j) return;
    if (s[i] == s[j]) {
        if(i==j)
            cout<<s[i];
        else{
            cout<<s[i];
            printt(i+1, j-1);
            cout<<s[i];
        }
        return;
    }

    ll opt = dp[i][j];
    ll op1 = solve(i+1, j)+1;
    if(opt==op1){
        cout<<s[i];
        printt(i+1, j);
        cout<<s[i];
        return;
    }
    else{
        cout<<s[j];
        printt(i, j-1);
        cout<<s[j];
        return;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin>>s){
        n = s.length();
        dp = vector<vector<int>>(n,vector<int>(n, -1));
        cout<<solve(0, n-1)<<" ";
        printt(0, n-1);
        cout<<endl;
    }



}



