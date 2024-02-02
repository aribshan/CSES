#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> idg(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        idg[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> tq;
    for(int i=1; i<=n; i++){
        if(idg[i] == 0){
            tq.push(i);
        }
    }

    vector<int> toposort; 

    while(!tq.empty()){
        int node = tq.top();
        tq.pop();
        toposort.push_back(node);

        for(auto x : adj[node]){
            idg[x]--;
            if(idg[x] == 0){
                tq.push(x);
            }
        }
    }

    if(toposort.size() < n){
        cout << 0 << '\n';
    }
    else{

        // for(auto x : toposort){
        //     cout << x << ' ';
        // }
        // cout << '\n';
        vector<int> ways(n+1, 0);
        ways[1] = 1;
        int idx = 0;
        for(int i=0; i<n; i++){
            if(toposort[i] == 1){
                idx = i;
            }
        }

        for(int i=idx; i<n; i++){
            //cout << toposort[i] << '\n';
            for(auto x : adj[toposort[i]]){
                //cout << x << ' ';
                ways[x] = (ways[toposort[i]]+ways[x])%mod;
            }
            //cout << '\n';
        }

        // for(int i=1; i<=n; i++){
        //     cout << i << ' ' << ways[i] << '\n';
        // }
        cout << ways[n] << '\n';
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

