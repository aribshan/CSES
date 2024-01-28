#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
vector<int> arr;
vector<vector<int>> dp;
int mod = 1e9+7;

int rec(int idx, int prev){
    if(idx == n) return 1;
    if(arr[idx] != 0 && prev != -1 && (prev > arr[idx]+1 || prev < arr[idx]-1)) return 0;
    if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];

    int ans = 0;
    int lb = max((long long)0, prev-1);
    int ub = min(m, prev+1);

    for(int i=lb; i<=ub; i++){
        ans = (ans + rec(idx+1, i))%mod;
    }

    return dp[idx][prev] = ans;
}

void solve(){
    cin >> n >> m;

    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    dp.resize(n+1, vector<int>(m+1, -1));

    int ans = rec(0, -1);

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
