#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 4, M = 2e3 + 9, mod = 1e9 + 7, inf = 0x3f3f3f;

ll n, m;

int cost[26][26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size()!=s2.size())
        return cout<<-1,0;
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < 26; ++j){
            cost[i][j] = inf;
            if(i == j) cost[i][j] =0;
        }
    }
    cin>>m;
    for(int i = 0; i < m; ++i){
        char u, v;
        int c;
        cin >> u >> v >> c;
        cost[u-'a'][v-'a'] = min(cost[u-'a'][v-'a'], c);
    }
    for(int k = 0; k < 26; ++k)
        for(int i = 0; i < 26; ++i)
            for(int j = 0; j < 26; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);


    int ans = 0;
    string out;
    for(int i =0; i<s1.size();++i){
        int tmp = inf;
        int one = s1[i]-'a', two =s2[i]-'a', l =-1;
        for(int newc =0; newc<26; ++newc){
            int newcost = cost[one][newc]+cost[two][newc];
            if(newcost<tmp){
                tmp = newcost;
                l = newc;
            }

        }
        if(l==-1)
            return cout<<-1, 0;
        out.push_back(char(l+'a'));
        ans+=tmp;
    }
    cout<<ans<<endl;
    cout<<out;
}



