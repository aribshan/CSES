#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    vector<int> ans;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    vector<int> vis(n+1, 0);

    while(!pq.empty() && vis[n] < q){
        int node = pq.top().second;
        int cost = pq.top().first;
        //cout << node << ' ' << cost << '\n';

        pq.pop();
        vis[node]++;
        if(node == n){
            ans.push_back(cost);
        }

        if(vis[node] <= q){
            for(auto x : adj[node]){
                pq.push({x.second+cost, x.first});
            }
        }
    }

    //sort(ans.begin(), ans.end());
    for(int i=0; i<q; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}

