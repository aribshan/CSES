#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    vector<int> ans;

    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(auto x : adj[node]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }

    if(ans.size() != n){
        cout << "IMPOSSIBLE" <<'\n';
    }
    else{
        for(int i=0; i<n; i++){
            cout << ans[i] << ' ';
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

