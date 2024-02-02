#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> cost(n+1, vector<int>(n+1, 1e14));

    for(int i=1; i<=n; i++){
        cost[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], c);
        cost[b][a] = min(cost[b][a], c);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
            }
        }
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        int ans = cost[a][b]==1e14 ? -1 : cost[a][b];
        cout << ans << '\n';
    }
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    int t;
    solve();

    return 0;
}

