#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());

    int ans = max(sum, 2*arr[n-1]);

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
