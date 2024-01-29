#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n+1, 1e8);
    vector<int> prev(n+1);

    queue<pair<int,int>> q;
    q.push({1,1});

    while(!q.empty()){
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for(auto x : adj[node]){
            if(dist[x] == 1e8){
                dist[x] = d+1;
                prev[x] = node;
                q.push({x, d+1});
            }
        }
    }

    if(dist[n] == 1e8){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        cout << dist[n] << '\n';
        vector<int> ans;
        int val = n;
        while(val != 1){
            ans.push_back(val);
            val = prev[val];
        }
        ans.push_back(val);

        reverse(ans.begin(), ans.end());
        for(auto x : ans){
            cout << x << ' ';
        }
        cout << '\n';
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
