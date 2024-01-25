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

    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int mn = INT_MAX;
    for(int i=0; i<(1<<n); i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                count += arr[j];
            }
        }
        mn = min(mn, abs(sum - 2*count));
    }

    cout << mn << '\n';



    return 0;
}
