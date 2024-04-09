#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> adj[200005];
int sum[200005];
int idp[200005];
int odp[200005];

void dfs2(int node, int parent){
    odp[node] = max(odp[node], sum[1] - sum[node]);
    if(parent == 0) odp[node] = 0;

    int mx1 = -2, mx2 = -2;

    for(int x : adj[node]){
        if(x == parent) continue;
        if(idp[x] > mx1){
            mx2 = mx1;
            mx1 = idp[x];
        }
        else if(idp[x] > mx2){
            mx2 = idp[x];
        }
    }

    for(int x : adj[node]){
        if(x == parent) continue;
        if(idp[x] == mx1){
            odp[x] = mx2 + 1;
        }
        else{
            odp[x] = mx1 + 1;
        }
        dfs2(x, node);
    }
}

void dfs(int node, int parent){
    sum[node] = 1;
    idp[node] = 0;

    for(int x : adj[node]){
        if(x == parent) continue;
        dfs(x, node);
        sum[node] += sum[x];
        idp[node] = max(idp[node], sum[x]);
    }
}

void solve(){
    cin >> n;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for(int i=1; i<=n; i++){
        if(max(idp[i], odp[i]) <= (n / 2)){
            cout << i << '\n';
            break;
        }
    }
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}