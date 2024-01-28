#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<vector<int>> arr(n, vector<int>(2));

    for(int i=0; i<n; i++){
        cin >> arr[i][0];
    }
    for(int i=0; i<n; i++){
        cin >> arr[i][1];
    }

    vector<int> dp(x+1, 0);
    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=x; j>=0; j--){
            if(j + arr[i][0] <= x){
                dp[j+arr[i][0]] = max(dp[j+arr[i][0]], dp[j]+arr[i][1]);
                ans = max(ans, dp[j+arr[i][0]]);
            }
        }
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
