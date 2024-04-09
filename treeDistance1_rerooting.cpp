#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> adj[200005];
int sa[200005];
int dp[200005];

void dfs2(int node, int parent){
    int mx1 = -2, mx2 = -2;

    for(int x : adj[node]){
        if(x == parent) continue;
        if(sa[x] > mx1){
            mx2 = mx1;
            mx1 = sa[x];
        }
        else if(sa[x] > mx2){
            mx2 = sa[x];
        }
    }

    for(int x : adj[node]){
        if(x == parent) continue;
        if(sa[x] == mx1){
            dp[x] = mx2 + 2;
        }
        else{
            dp[x] = mx1 + 2;
        }
        dp[x] = max(dp[x], dp[node] + 1);
        dfs2(x, node);
    }
}

void dfs(int node, int parent){
    sa[node] = 0;

    for(int x : adj[node]){
        if(x == parent) continue;
        dfs(x, node);
        sa[node] = max(sa[node], sa[x] + 1);
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
        cout << max(dp[i], sa[i]) << ' ';
    }
    cout << '\n';
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