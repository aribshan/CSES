#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int count = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i+1] <= arr[i]){
            count += arr[i]-arr[i+1];
            arr[i+1] = arr[i];
        }
    }

    cout << count << '\n';

    return 0;
}
