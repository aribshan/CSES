#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll exp(ll x, ll n, ll m){  // {number, power, mod}
    x %= m;
    ll res = 1;

    while(n > 0){
        if(n % 2 == 1) res = res * x % m;
        x = x * x % m;
        n /= 2;
    }

    return res;
}

ll inverse(int x, int m){ // {number, mod}
    return exp(x, MOD - 2, MOD);
}

void solve(){
    int n;
    cin >> n;

    int val = (n * (n + 1)) / 2;

    if(val % 2){
        cout << 0 << '\n';
        return;
    }
    val/=2;

    vector<int> dp(val+1, 0);
    dp[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=val-i; j>=0; j--){
            dp[j+i] += dp[j];
            dp[j+i] %= MOD;
        }
    }

    int ans = (dp[val] * inverse(2, MOD)) % MOD;
    cout << ans << '\n';
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