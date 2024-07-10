#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<bitset<50005>> arr(n+1);
    vector<vector<int>> adj(n+1);
    vector<int> idg(n+1, 0);
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        idg[a]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        arr[i][i] = 1;
        if(idg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int x : adj[node]){
            idg[x]--;
            arr[x] |= arr[node];
            if(idg[x] == 0) q.push(x);
        }
    }

    for(int i=1; i<=n; i++){
        cout << arr[i].count() << ' ';
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