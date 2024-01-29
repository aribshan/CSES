#include <bits/stdc++.h>
#define int long long
using namespace std;

int timer = 1;
void dfs(int node, int parent, vector<int>&vis, vector<vector<int>>&adj, int tin[], int low[], vector<vector<int>>& bridges){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for(auto it : adj[node]){
        if(it == parent) continue;
        if(vis[it] == 0){
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                bridges.push_back({it, node});
            }
        }
        else{
            low[node] = min(low[node], low[it]);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n, 0);
    int tin[n];
    int low[n];

    vector<vector<int>> bridges;

    dfs(0, -1, vis, adj, tin, low, bridges);

    cout << bridges.size() << '\n';
    for(auto &x : bridges){
        cout << x[0]+1 << ' ' << x[1]+1 << '\n';
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
