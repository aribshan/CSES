#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int,int> mp;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b+1]--;
    }

    int curr = 0, mx = 0;

    for(auto it : mp){
        curr += it.second;
        mx = max(mx, curr);
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
