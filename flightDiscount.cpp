#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
     cin >> n >> m;

     vector<vector<pair<int,int>>> adj(n);
     for(int i=0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;

        adj[x].push_back({y, z});
     }

     vector<int> cost1(n, 1e18);
     vector<int> cost2(n, 1e18);
     cost1[0] = 0;
     cost1[0] = 0;

     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

     pq.push({0, 0});

     while(!pq.empty()){
        int node = pq.top().second;
        int c1 = cost1[node];
        int c2 = cost2[node];
        int cost = pq.top().first;

        pq.pop();
        if(c1 + c2 < cost) continue;

        for(auto x : adj[node]){
            bool ok = false;
            if(x.second+c1 < cost1[x.first]){
                cost1[x.first] = x.second+c1;
                ok = true;
            }
            if(x.second/2 + c1 < cost2[x.first]){
                cost2[x.first] = (x.second)/2 + c1;
                ok = true;
            }
            if(x.second+c2 < cost2[x.first]){
                cost2[x.first] = x.second + c2;
                ok = true;
            }
            if(ok) pq.push({cost1[x.first]+cost2[x.first], x.first});
        }
     }

     cout << cost2[n-1] << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
