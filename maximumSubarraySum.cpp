#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n+1, 0);
    for(int i=1; i<=n; i++){   
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    int currMin = 0, mx = INT_MIN;

    for(int i=1; i<=n; i++){
        //cout << arr[i] << ' ';

        mx = max(mx, arr[i]-currMin);
        currMin = min(currMin, arr[i]);
    }

    cout << mx << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
