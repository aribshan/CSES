#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> dp(x+1, 1e7);

    dp[0] = 0;

    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(i-arr[j] >= 0){
                dp[i] = min(dp[i], 1+dp[i-arr[j]]);
            }
        }
    }

    // for(int i=0; i<=x; i++){
    //     cout << dp[i] << ' ';
    // }

    int ans = dp[x]>=1e7 ? -1 : dp[x];

    cout << ans << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
