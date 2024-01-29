#include <bits/stdc++.h>
#define int long long
using namespace std;

int mp[1000001];

void sieve(int n) {
    for (int i=1; i<=n; i++){
        mp[i] = i;
    }
    for (int p=2; p*p<=n; p++) {
        if (mp[p] == p) {
            for (int i=p*p; i<=n; i += p) 
                if (mp[i]==i) mp[i]=p; 
        }
    } 
}

void solve(){
    int x;
    cin >> x;

    int ans = 1;
    while(x != 1){
        int y = mp[x];
        int c = 1;
        while(x%y == 0){
            c++;
            x/=y;
        }
        ans *= c;
    }

    cout << ans << '\n';

}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    int t;
    cin >> t;

    sieve(1000000);

    while(t--){
        solve();
    }

    return 0;
}
