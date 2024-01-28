#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    int sum = 0;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    //cout << n << '\n';

    vector<bool>dp(sum+1, 0);
    dp[0] = true;

    for(int i=0; i<n; i++){
        for(int j=sum; j>=0; j--){
            if(dp[j] && j+arr[i] <= sum){
                dp[j+arr[i]] = true;
            }
        }
    }

    int count = 0;
    for(int i=1; i<=sum; i++){
        if(dp[i]) count++;
    }

    cout << count << '\n';
    for(int i=1; i<=sum; i++){
        if(dp[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
