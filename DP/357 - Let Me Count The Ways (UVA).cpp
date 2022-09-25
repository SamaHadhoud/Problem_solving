#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e2 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int n;
vector<vector<ll>> mem(5,vector<ll>(30000+1, -1));
int coins[]={1,5,10,25,50};


ll solve(int cur, int r){
    if(r==0) return 1;
    if(cur==5) return 0;
    if(mem[cur][r]!=-1)
        return mem[cur][r];
    ll op1= (r-coins[cur]>=0) ? solve(cur, r-coins[cur]): 0;
    ll op2= solve(cur+1, r);
    return mem[cur][r]=op1+op2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin>>n){
        ll ans =solve(0,n);
        if(ans!=1)
            cout<<"There are "<<ans<<" ways to produce "<<n <<" cents change."<<endl;
        else
            cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;


    }
}



