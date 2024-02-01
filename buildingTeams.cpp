#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
vector<int> teams;
bool ok = true;

void dfs(int node, int prev){
    teams[node] = 1-prev;

    for(auto x: adj[node]){
        if(teams[x]==1-prev){
            ok = false;
        }
        if(teams[x]==-1){
            dfs(x, 1-prev);
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    adj.resize(n);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    teams.resize(n, -1);

    for(int i=0; i<n; i++){
        if(teams[i] == -1){
            dfs(i, 1);
        }
    }

    if(ok){
        for(int i=0; i<n; i++){
            cout<<teams[i]+1 << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
