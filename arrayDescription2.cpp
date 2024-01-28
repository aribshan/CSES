#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;

    //cout << n << ' ' << m << ' ';

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << ' ';
    // }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    if(arr[0] == 0){
        for(int i=1; i<=m; i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][arr[0]] = 1;
    }


    for(int i=1; i<=n; i++){
        if(arr[i] == 0){
            for(int j=1; j<=m; j++){
                int val = 0;
                for(int k=-1; k<=1; k++){
                    val += (j+k>=1 && j+k<=m) ? dp[i-1][j+k] : (long long)0;
                }
                dp[i][j] = val%mod;
            }
        }
        else{
            int lb = max((long long)1, arr[i]-1);
            int ub = min(m, arr[i]+1);
            for(int j=lb; j<=ub; j++){
                dp[i][arr[i]] += dp[i-1][j];
                dp[i][arr[i]] %= mod;
            }
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for(int i=0; i<=m; i++){
        ans = (ans+dp[n-1][i])%mod;
    }

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
