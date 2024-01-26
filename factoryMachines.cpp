#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = INT_MAX;
    int l = 0, r = *min_element(arr.begin(), arr.end())*t;
    while(l <= r){
        int mid = l + (r-l)/2;

        int count = 0;
        for(int i=0; i<n; i++){
            count += (mid/arr[i]);
        }

        if(count >= t){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
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
