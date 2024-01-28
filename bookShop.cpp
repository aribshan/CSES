#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> arr, dp;
int n, x;

int rec(int idx, int price){
    if(idx >= n) return 0;
    if(dp[idx][price] != -1) return dp[idx][price];

    int ans;
    ans = rec(idx+1, price);

    if(price + arr[idx][0] <= x){
        ans = max(ans, arr[idx][1] + rec(idx+1, price+arr[idx][0]));
    }

    //cout << price << '-' <<  ans  << '\n';

    return dp[idx][price] = ans;
}

void solve(){
    cin >> n >> x;

    arr.resize(n+1, vector<int>(2));
    dp.resize(n+1, vector<int>(x+1, -1));
    for(int i=0; i<n; i++){
        cin >> arr[i][0];
    }
    for(int i=0; i<n; i++){
        cin >> arr[i][1];
    }


    int ans = rec(0, 0);

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
