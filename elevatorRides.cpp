#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }

    vector<pair<int,int>> dp((1<<n));
    dp[0] = {1, 0};

    for(int i=1; i<(1<<n); i++){
        dp[i] = {21, 0};
        for(int j=0; j<n; j++){
            if((i & (1<<j)) == 0) continue;
            auto curr = dp[i ^ (1<<j)];
            int rides = curr.first;
            int weight = curr.second;
            if(weight + arr[j] > k){
                rides++;
                weight = min(arr[j], weight);
            }
            else{
                weight += arr[j];
            }
            dp[i] = min(dp[i], {rides, weight});
        }
    }

    cout << dp[(1<<n) - 1].first << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}