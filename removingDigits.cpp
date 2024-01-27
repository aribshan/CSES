#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n+1, 1e8);
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        int val = i;
        while(val){
            int dig = val%10;
            dp[i] = min(dp[i], dp[i-dig]+1);
            val /= 10;
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
