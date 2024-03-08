#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> par;
vector<vector<int>> adj;
vector<int> depth;

void dfs(int node, int prev, int dist){
    par[node][0] = prev;
    depth[node] = dist;

    for(int i=1; i<20; i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }

    for(auto x : adj[node]){
        if(x != prev){
            dfs(x, node, dist+1);
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    par.resize(n, vector<int>(20));
    adj.resize(n);
    depth.resize(n, 0);

    for(int i=1; i<n; i++){
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
    }

    dfs(0, 0, 0);

    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b;

        if(b>depth[a]){
            cout << -1 <<'\n';
            continue;
        }

        for(int i=19; i>=0; i--){
            if(b&(1<<i)){
                a = par[a][i];
            }
        }

        cout << a+1 << '\n';

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

