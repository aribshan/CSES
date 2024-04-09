#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int MOD = 1e9 + 7;

    int a = 1, b = 0;
    for(int i=2; i<=n; i++){
        int c = ((i - 1) * (a + b)) % MOD;
        a = b;
        b = c;
    }

    cout << b << '\n';
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