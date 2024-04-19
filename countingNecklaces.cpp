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

void solve(){
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = (ans + exp(m, __gcd(i, n), MOD)) % MOD;
    }
    ans = ans * exp(n, MOD - 2, MOD) % MOD;

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