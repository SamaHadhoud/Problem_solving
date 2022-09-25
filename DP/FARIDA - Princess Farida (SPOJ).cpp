#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e4 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

int n;
int arr[N];
ll mem[N];

ll solve(int i){
    if(i>=n) return 0;
    if(mem[i]!=-1)
        return mem[i];
    return mem[i]=max(solve(i+1), solve(i+2)+arr[i]);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    for(int tc =1; tc<=t;++tc) {
        cin >> n;
        fill(mem, mem+N, -1);
        for(int i = 0; i < n; ++i){
            cin>>arr[i];
        }
        cout<<"Case "<<tc<<": "<<solve(0)<<endl;

    }
}



