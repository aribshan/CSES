#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << arr[b]-arr[a-1] << '\n';
    }

}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();
    return 0;
}

