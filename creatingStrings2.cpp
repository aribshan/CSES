#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

// dont forget to call factorial and inverses in main for precalc
ll fac[MAXN + 1];
ll inv[MAXN + 1];

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

void factorial(){
    fac[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
}

void inverses(){
    inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
    for(int i = MAXN; i >= 1; i--){
        inv[i - 1] = inv[i] * i % MOD;
    }
}

ll choose(int n, int r){
    if(n - r < 0 || r < 0) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

ll chooseSlow(int n, int r){
    if(n - r < 0 || r < 0) return 0;
    int res = 1;

    for(int i=n; i>n-r; i--){
        res *= i;
    }
    for(int i=2; i<=r; i++){
        res /= i;
    }

    return res;
}

void solve(){
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for(auto ch : s){
        freq[ch - 'a']++;
    }

    int n = s.length();

    int ans = fac[n];

    for(auto x : freq){
        ans = (ans * inv[x]) % MOD;
    }

    cout << ans << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    factorial();
    inverses();

    solve();

    return 0;
}