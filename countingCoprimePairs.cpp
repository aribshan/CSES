#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> cnt(1e6+1, 0),cnt2(1e6+1, 0);
    for(auto &x : arr){
        cin >> x;
        cnt[x]++;
    }

    for(int i=1; i<=1e6; i++){
        for(int j=i; j<=1e6; j+=i){
            cnt2[i] += cnt[j];
        }
        cnt2[i] = (cnt2[i] * (cnt2[i] - 1)) / 2;
    }

    int ans = 0;
    for(int i=1e6; i>=1; i--){
        for(int j=2*i; j<=1e6; j+=i){
            cnt2[i] -= cnt2[j];
        }
    }

    cout << cnt2[1] << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}