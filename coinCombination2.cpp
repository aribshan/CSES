#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    const int mod = 1e9+7;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<=x; j++){
            if(j + arr[i] <= x){
                dp[j+arr[i]] += dp[j];
                dp[j+arr[i]] %= mod;
            }
        }
    }

    // for(int i=0; i<=x; i++){
    //     for(int j=0; j<n; j++){
    //         if(i + arr[j] <= x){
    //             dp[i+arr[j]] += dp[i];
    //             dp[i+arr[j]] %= mod;
    //         }
    //     }
    // }

    // for(auto x : dp){
    //     cout << x << ' ';
    // }

    cout << dp[x] << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
