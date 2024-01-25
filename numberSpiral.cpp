#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int r, c;
    cin >> r >> c;

    int ans;

    if(r>c){
        if(r%2 == 0){
            ans = r*r - c + 1;
        }
        else{
            ans = (r-1)*(r-1) + c;
        }
    }
    else{
        if(c%2 == 1){
            ans = c*c - r + 1;
        }
        else{
            ans = (c-1)*(c-1) + r;
        }
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

    while(t--){
        solve();
    }

    return 0;
}
