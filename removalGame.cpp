#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> arr;
vector<vector<int>> dp;

int rec(int l, int r){
    if(l == r) return arr[l];
    if(dp[l][r] != -1e15) return dp[l][r];

    int ans = max(arr[l]-rec(l+1, r), arr[r]-rec(l,r-1));

    return dp[l][r] = ans;
}

void solve(){
    cin >> n;
    arr.resize(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];

    }

    dp.resize(n+1, vector<int>(n+1, -1e15));

    int ans = rec(0, n-1);
    ans += (sum-ans)/2;

    cout << ans<< '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
