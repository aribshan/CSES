#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int curr = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > curr+1){
            //cout << arr[i] << ' ' << curr << ' ';
            curr++;
            cout << curr << '\n';
            return;
        }
        curr += arr[i];
    }
    curr++;
    cout << curr << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();
    return 0;
}
