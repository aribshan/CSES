#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        dp[i][0] = i;
    }
    for(int j=1; j<=m; j++){
        dp[0][j] = j;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }

    //int ans = max(n-dp[n][m], m-dp[n][m]);

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
