#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    int n;
    cin >> n;

    int ans = 1;
    int mod = 1e9+7;
    for(int i=0; i<n; i++){
        ans = (ans*2)%mod;
    }

    cout << ans << '\n';

    return 0;
}
