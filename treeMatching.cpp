#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> adj[200005];
int dp[200005][3];

int dfs(int node, int parent){
    int a = 1;
    dp[node][0] = 0;
    dp[node][1] = 0;

    for(int x : adj[node]){
        if(x == parent) continue;
        dfs(x, node);
        dp[node][0] += max(dp[x][0], dp[x][1]);
        a += max(dp[x][0], dp[x][1]);
    }

    for(int x : adj[node]){
        if(x == parent) continue;
        dp[node][1] = max(dp[node][1], a - max(dp[x][0], dp[x][1]) + dp[x][0]);
    }

    return max(dp[node][0], dp[node][1]);
}

void solve(){
    cin >> n;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    int ans = dfs(1, 0);

    // for(int i=1; i<=n; i++){
    //     cout << i << ' '<< dp[i][0] << ' ' << dp[i][1] << '\n';
    // }
    cout << ans << '\n';
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