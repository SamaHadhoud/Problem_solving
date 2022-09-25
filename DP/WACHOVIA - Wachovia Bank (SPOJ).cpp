#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e2 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int n, k;
int a[N], b[N];
vector<vector<int>>mem;

int solve(int i, int kr){
    if(i==n) return 0;
    if(mem[i][kr]!=-1)
        return mem[i][kr];
    int op1= (kr>=b[i]) ? solve(i+1, kr-b[i])+a[i]: INT_MIN;
    int op2= solve(i+1, kr);
    return mem[i][kr]=max(op1,op2);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        cin >> k>>n;
        mem=vector<vector<int>>(n, vector<int>(k+1,-1));
        for(int i = 0; i < n; ++i){
            cin>>b[i]>>a[i];
        }
        cout<<"Hey stupid robber, you can get "<<solve(0, k)<<"."<<endl;

    }
}



