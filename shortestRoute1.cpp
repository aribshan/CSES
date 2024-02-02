#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b,c});
    }

    vector<int> ans(n+1, 1e14);
    ans[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()){
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(cost > ans[node]){
            continue;
        }

        for(auto x : adj[node]){
            if(ans[x.first] > cost+x.second){
                ans[x.first] = cost+x.second;
                pq.push({ans[x.first], x.first});
            }
        }
    }

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
 
    solve();

    return 0;
}

