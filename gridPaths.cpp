#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    const int mod = 1e9+7;

    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }

    int m = grid[0].length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    if(grid[0][0] == '.' && grid[n-1][m-1] == '.'){
        dp[1][1] = 1;
    }
    //cout << dp[1][1] << '\n';

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //cout << grid[i][j]-'.' << '\n';
            if(grid[i][j]-'.' == 0){
                dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j];
                dp[i+1][j+1] %= mod;
            }
        }
    }

    cout << dp[n][m] << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
