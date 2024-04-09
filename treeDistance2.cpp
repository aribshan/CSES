#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> adj[200005];
int sa[200005];
int sum[200005];
int dp[200005];

void dfs2(int node, int parent){
    dp[node] += sum[1] - sum[node] + dp[parent];

    int s = 0;
    for(int x : adj[node]){
        if(x != parent){
            s += sa[x] + sum[x];
        }
    }

    for(int x : adj[node]){
        if(x == parent) continue;
        dp[x] += (s - (sa[x] + sum[x]));
        dfs2(x, node);
    }
}

void dfs(int node, int parent){
    sum[node] = 1;
    sa[node] = 0;

    for(int x : adj[node]){
        if(x == parent) continue;
        dfs(x, node);
        sa[node] += sa[x] + sum[x];
        sum[node] += sum[x];
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
        cout << sa[i] + dp[i] << ' ';
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