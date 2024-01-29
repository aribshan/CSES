#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        reverse(temp.begin(), temp.end());

        int val = 0;
        for(int j=0; j<k; j++){
            //cout << temp[j];
            if(temp[j]=='1'){
                val += (1<<j);
            }
            //val += (temp[j]=="1")*(1<<j);
        }

        arr[i] = val;
        //cout << val << '\n';
        //cout << '\n';
    }

    int ans = INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //cout << arr[i] << ' ' << arr[j] << '\n';
            ans = min(ans, (long long)__builtin_popcount(arr[i]^arr[j]));
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
