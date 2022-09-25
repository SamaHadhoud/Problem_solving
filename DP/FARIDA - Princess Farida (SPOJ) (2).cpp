#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 9,  M = 2*N, mod = 139+7, inf = 0x3f3f3f;
int n;


int main(){
    int t;
    cin>>t;
    for(int ct = 1; ct<=t;++ct){
        cin>>n;
        vector<int>arr(n+1);
        for(int i=1; i<=n; i++) cin>>arr[i];
        arr[0]=0;
        vector<ll>dp(n+2, 0);
        if(n>=1) dp[1]= arr[1];
        if(n>=2) dp[2]= max(arr[1],arr[2]);
        for(int i=3; i<=n; i++){
            dp[i]=max(dp[i-1], dp[i-2]+arr[i]);
        }

        cout<<"Case "<<ct<<": "<<dp[n]<<endl;
    }




    return 0;
}
