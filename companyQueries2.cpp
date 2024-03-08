#include <bits/stdc++.h>
#define int long long
using namespace std;

int par[200001][20];
vector<vector<int>> adj;
int depth[200001];

void dfs(int node, int prev, int dist){
    par[node][0] = prev;
    depth[node] = dist;

    for(auto x : adj[node]){
        if(x != prev){
            dfs(x, node, dist+1);
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    adj.resize(n+1);

    for(int i=2; i<=n; i++){
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, 0, 0);

    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            if(par[j][i-1] != 0){
                par[j][i] = par[par[j][i-1]][i-1];
            }
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        if(depth[a] < depth[b]){
            swap(a, b);
        }

        for(int i=19; i>=0; i--){
            if(depth[a] >= depth[b] + (1 << i)){
                a = par[a][i];
            }
        }

        if(a == b){
            cout << a << '\n';
        }
        else{
            for(int i=19; i>=0; i--){
                if(par[a][i] != 0 && par[a][i] != par[b][i]){
                    a = par[a][i];
                    b = par[b][i];
                }
            }

            cout << par[a][0] << '\n';
        }  
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

