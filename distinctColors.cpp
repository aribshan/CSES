#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int arr[200005];
int ans[200005];
set<int> dc[200005];
vector<int> adj[200005];

void dfs(int node, int parent){
    dc[node] = {arr[node]};

    for(int x : adj[node]){
        if(x == parent) continue;
        dfs(x, node);

        if(dc[node].size() < dc[x].size()){
            swap(dc[x], dc[node]);
        }
        for(int y : dc[x]){
            dc[node].insert(y);
        }
    }

    // cout << node << '\n';
    // for(int x : dc[node]){
    //     cout << x << ' ';
    // }
    // cout << '\n';

    ans[node] = (int) dc[node].size();
}

void solve(){
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        // cout << a << ' ' << b << '\n';
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(int i=1; i<=n; i++){
        cout << ans[i] << ' ';
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