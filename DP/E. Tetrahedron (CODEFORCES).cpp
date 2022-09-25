#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 9,  M = 2*N, mod = 1e9+7, inf = 0x3f3f3f;
int n;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    ll PA=0, PB=0, PC=0, PD=1, CA, CB, CC, CD;
    while(n--){
        CA =(PB+PC+PD)%mod;
        CB =(PA+PC+PD)%mod;
        CC =(PB+PA+PD)%mod;
        CD =(PB+PC+PA)%mod;
        PA =CA;
        PB =CB;
        PC = CC;
        PD=CD;
    }
    cout<<CD;




    return 0;
}
