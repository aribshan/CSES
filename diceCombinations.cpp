#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    const int mod = 1e9+7;

    int dp[n+10];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=1; j<=6; j++){
            dp[i+j] += dp[i];
            dp[i+j] %= mod;
        }
    }

    cout << dp[n] << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
