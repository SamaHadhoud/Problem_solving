#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f3f;

int n;
vector<int>row,col;
vector<vector<int>>mem;


int solve(int s, int e){
    if(s==e) return 0;
    if(mem[s][e]!=-1) return mem[s][e];
    int ret=inf;
    for(int i=s; i<e; i++)
        ret=min(ret, solve(s,i)+solve(i+1,e)+row[s]*col[i]*col[e]);
    return mem[s][e]=ret;
}

void print(int s, int e){
    if(s==e) {cout<<"A"<<s+1;return;}
    int opt=solve(s, e);
    int mid =-1;
    for(int i=s; (i<e) && (mid==-1); i++) {
        int cur = solve(s, i) + solve(i + 1, e) + row[s] * col[i] * col[e];
        if (cur == opt)
            mid =i;
    }
    cout<<"(";
    print(s, mid);
    cout<<" x ";
    print(mid+1, e);
    cout<<")";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt =0;
    while(cin>>n, n){
        row.resize(n);
        col.resize(n);
        mem=vector<vector<int>>(n,vector<int>(n,-1));
        for(int i=0; i<n; i++) cin>>row[i]>>col[i];
        solve(0,n-1);
        cout<<"Case "<<++cnt<<": ";
        print(0,n-1);
        cout<<endl;
    }




}



