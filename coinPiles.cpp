#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int left, right;
    cin >> left >> right;

    int sum = left+right;
    if(left > 2*right || right > 2*left || ((sum)%3)){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
    }
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
