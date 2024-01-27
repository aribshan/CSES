#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> arr(n+1, 0);

    for(int i=1; i<=n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    unordered_map<int,int> mp;
    int cnt = 0;
    for(int i=0; i<=n; i++){
        //cout << arr[i] << '_' << arr[i]-x << '_' << mp.count(arr[i]-x) << ' ';
        if(mp.count(arr[i]-x)){
            cnt += mp[arr[i]-x];
        }
        mp[arr[i]]++;
    }

    cout << cnt << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
