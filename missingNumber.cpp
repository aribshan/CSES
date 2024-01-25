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
    vector<int> arr(n-1);
    int x = 0;
    for(int i=0; i<n-1; i++){
        cin >> arr[i];
        x ^= arr[i];
        x ^= (i+1);
    }

    x^=n;

    cout << x << '\n';

    return 0;
}
