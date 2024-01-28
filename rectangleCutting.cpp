#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int mx = max(a,b);
    vector<vector<int>> dp(1+mx, vector<int>(1+mx, 1e8));

    for(int i=0; i<=mx; i++){
        for(int j=0; j<=mx; j++){
            if(i == j){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=0; i<=mx; i++){
        for(int j=0; j<=mx; j++){
            for(int k=1; k<mx; k++){
                int x = dp[i][j];
                int y = k<i ? 1+dp[i-k][j]+dp[k][j] : 1e8;
                int z = k<j ? 1+dp[i][j-k]+dp[i][k] : 1e8;

                dp[i][j] = min({x, y, z});
            }
        }
    }

    cout << dp[a][b] << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
 