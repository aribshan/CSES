#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_SIZE = 200005;
const int MAX_LEVELS = 21;

int n, q;
vector<int> adj[200005];

int depth[MAX_SIZE];
int parents[MAX_SIZE][MAX_LEVELS];

void dfs(int node, int parent) {  
    for(int i: adj[node]) {
        if(i != parent) {
            parents[i][0] = node;
            depth[i] = depth[node] + 1;
            dfs(i, node);
        }
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    int dist = depth[u]-depth[v];
    int z = 0;
    while(dist > 0){
        if(dist & 1){
            u = parents[u][z];
        }
        z++;
        dist>>=1;
    }
    
    if(u == v) {
        return u;
    }
    for(int i = MAX_LEVELS - 1; i >= 0; i --) {
        if (parents[u][i] != 0 && parents[u][i] != parents[v][i]) {
            u = parents[u][i];
            v = parents[v][i];
        }
    }
    return parents[u][0];
}

void solve(){
    cin >> n >> q;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    for(int i = 1; i < MAX_LEVELS; i++) {
        for(int j = 1; j <= n; j++) {
            if(parents[j][i - 1] != 0) {
                parents[j][i] = parents[parents[j][i - 1]][i - 1];
            }
        }
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        int par = lca(u, v);

        int ans = depth[u] + depth[v] - 2*depth[par];

        cout << ans << '\n';
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    
    solve();

    return 0;
}