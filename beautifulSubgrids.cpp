#include <bits/stdc++.h>
#pragma GCC target("popcnt")
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<bitset<3000>> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int temp = (arr[i]&arr[j]).count();
            ans += (temp*(temp-1))/2;
        }
    }

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
