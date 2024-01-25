#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int count = 0;
    int l = 0, r = n-1;
    while(l<=r){
        if(l == r){
            count++;
            r--;
            l++;
        }
        else if(arr[l]+arr[r] > x){
            count++;
            r--;
        }
        else if(arr[l] + arr[r] <= x){
            count++;
            r--;
            l++;
        }

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
