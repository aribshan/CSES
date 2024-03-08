#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_SIZE = 1 << 20;
const int MAX_LEVELS = 20;

int n, q;
vector<vector<int>> adj;
vector<int> prefix;

int depth[MAX_SIZE];
int parents[MAX_SIZE][MAX_LEVELS];

void dfs(int node, int parent) {
    parents[node][0] = parent;
    for(int i: adj[node]) {
        if(i != parent) {
            depth[i] = depth[node] + 1;
            dfs(i, node);
        }
    }
}

int dfs2(int node, int parent){
    int sum = 0;
    for(auto x : adj[node]){
        if(x != parent){
            sum += dfs2(x, node);
        }
    }
    sum += prefix[node];
    prefix[node] = sum;
    return sum;
}

int lca(int u, int v) {
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
    for(int i = MAX_LEVELS - 1; i >= 0; i--) {
        if (parents[u][i] != 0 && parents[u][i] != parents[v][i]) {
            u = parents[u][i];
            v = parents[v][i];
        }
    }
    return parents[u][0];
}

void solve(){
    cin >> n >> q;
    adj.resize(n + 1);

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

    prefix.resize(n+1, 0);

    while(q--) {
        int u, v;
        cin >> u >> v;
        if(depth[u] < depth[v]) {
            swap(u, v);
        }

        int par = lca(u, v);

        //cout << u << ' ' << v << ' ' << par << '\n';
        if(par == v){
            prefix[parents[par][0]]--;
            prefix[u]++;
        }
        else{
            prefix[v]++;
            prefix[u]++;
            prefix[par]--;
            prefix[parents[par][0]]--;
        }
    }

    // for(int i=0; i<=n; i++){
    //     cout << prefix[i] << ' ';
    // }
    // cout << '\n';

    dfs2(1, 0);

    for(int i=1; i<=n; i++){
        cout << prefix[i] << ' ';
    }
    cout << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    
    solve();

    return 0;
}