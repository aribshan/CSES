#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> arr;
bool chk(int sum, int k){
    int curr = 0, i = 0;

    for(i=0; i<arr.size(); i++){
        curr += arr[i];
        if(curr > sum){
            k--;
            curr = arr[i];
        }
        
        if(curr > sum){
            k = -1;
        }
        //cout << curr << '-' << k << ' ';
    }

    return ((k>=0) && (curr <= sum));
}

void solve(){
    int n, k;
    cin >> n >> k;

    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int l = 0, r = 0;
    for(auto x : arr){
        r += x;
    }

    int ans = 0;

    //cout << chk(5, 3) << '\n';

    while(l<=r){
        int mid = l + (r-l)/2;

        if(chk(mid, k-1)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    cout << ans << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
