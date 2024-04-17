#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll exp(ll x, ll n, ll m = MOD){  // {number, power, mod}
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

int mod_mul(int a, int b){
    a %= MOD;
    b %= MOD;
    return a * b % MOD;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), brr(n);

    bool ok = true;
    for(int i=0; i<n; i++){
        cin >> arr[i] >> brr[i];
        if(brr[i] % 2) ok = false;
    }

    int a = 1, b = 1, c = 1;
    int cnt = 1;
    
    for(int i=0; i<n; i++){
        a = mod_mul(a, brr[i] + 1);
        b = mod_mul(b, mod_mul(exp(arr[i], brr[i]+1, MOD) - 1, inverse(arr[i] - 1, MOD)));
        c = mod_mul(exp(c, brr[i] + 1), exp(exp(arr[i], ((brr[i] * (brr[i] + 1)) / 2)), cnt));
        cnt = (cnt * (brr[i] + 1)) % (MOD - 1);
    }

    cout << a << ' ' << b << ' ' << c << '\n';

}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif

    solve();

    return 0;
}