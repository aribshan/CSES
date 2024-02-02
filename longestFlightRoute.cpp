#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    //vector<vector<int>> revAdj(n+1);
    vector<int> idg(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        //revAdj[b].push_back(a);
        idg[b]++;

    }

    queue<int> topo;
    vector<int> toposort;
    for(int i=1; i<=n; i++){
        if(idg[i] == 0){
            topo.push(i);
        }
    }

    while(!topo.empty()){
        int node = topo.front();
        topo.pop();
        toposort.push_back(node);

        for(auto x : adj[node]){
            idg[x]--;
            if(idg[x] == 0){
                topo.push(x);
            }
        }
    }

    //cout << "DONE" << '\n';

    if(toposort.size() < n){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        vector<int> prev(n+1, 1);
        vector<int> dist(n+1, -1e10);
        dist[1] = 0;
        for(int i=0; i<n; i++){
            // cout << toposort[i] << ' ';
            for(auto x: adj[toposort[i]]){
                if(dist[toposort[i]]+1 > dist[x]){
                    dist[x] = dist[toposort[i]]+1;
                    prev[x] = toposort[i];
                }
            }
        }

        // cout << "DONE" << '\n';

        // if(dist[n] > 0){
        //     cout << dist[n]+1 << '\n';
        // }

        // for(int i=1; i<=n; i++){
        //     cout << i << ' ' << prev[i] <<' ' << dist[i] << '\n';
        // }

        if(dist[n] > 0){
            cout << dist[n]+1 << '\n';
            int node = n;
            vector<int> ans;
            while(node != 1){
                ans.push_back(node);
                node = prev[node];
            }
            ans.push_back(1);
            reverse(ans.begin(), ans.end());

            for(auto x : ans){
                cout << x << ' ';
            }
            cout << '\n';
        }
        else{
            cout << "IMPOSSIBLE" << '\n';
        }
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

