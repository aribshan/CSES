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

    int mid;

    if(n%2){
        mid = arr[n/2];
    }
    else{
        mid = (arr[n/2] + arr[n/2-1])/2;
    }

    int count = 0;
    for(int i=0; i<n; i++){
        count += abs(arr[i] - mid);
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
