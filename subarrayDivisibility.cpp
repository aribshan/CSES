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
        arr[i] %= n;
        arr[i] += 1e10;
        arr[i] %= n;
    }
    //0 3 4 6 13 17
    //0 3 4 1 3 2
 
    unordered_map<int,int> mp;
    int cnt = 0;
    for(int i=0; i<=n; i++){
        //cout << arr[i] << '_' << arr[i] << '_' << mp.count(arr[i]) << ' ';
        if(mp.count(arr[i])){
            cnt += mp[arr[i]];
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
