#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> depth;
int endVal;
int mxDis = 0;
void dfs(int node, int dist){
    depth[node] = dist;
    if(dist > mxDis){
        mxDis = dist;
        endVal = node;
    }

    for(auto x : adj[node]){
        if(depth[x] == 0){
            dfs(x, dist+1);
        }
    }
}

void dfs2(int node, int dist){
    depth[node] = dist;
    mxDis = max(mxDis, dist);

    for(auto x : adj[node]){
        if(depth[x] == 0){
            dfs(x, dist+1);
        }
    }
}

void solve(){
    cin >> n;
    adj.resize(n);
    depth.resize(n, 0);

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 1);
    depth.clear();
    depth.resize(n, 0);

    dfs2(endVal, 1);

    cout << mxDis-1 << '\n';

}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}

