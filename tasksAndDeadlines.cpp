#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    sort(arr.begin(), arr.end());

    int curr= 0;
    int count = 0;
    for(int i=0; i<n; i++){
        curr += arr[i][0];
        count += arr[i][1] - curr;
    }

    cout << count << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
