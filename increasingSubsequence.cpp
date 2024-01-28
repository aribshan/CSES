#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        int idx = lower_bound(arr.begin(), arr.end(), a)-arr.begin();
        if(idx >= arr.size()){
            arr.push_back(a);
        }
        else{
            arr[idx] = a;
        }
    }

    cout << arr.size() << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
