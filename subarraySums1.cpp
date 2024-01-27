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

    int l = 0, r = 0;
    int curr = 0, count = 0;

    while(l < n){
        if(curr == x){
            count++;
            curr -= arr[l];
            l++;
        }
        if(curr < x){
            if(r < n){
                curr += arr[r];
                r++;
            }
            else{
                l++;
            }
        }
        else{
            curr -= arr[l];
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
