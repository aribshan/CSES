#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());

    int l = 0, r = n-1;
    while(l < r){
        if(arr[l].first + arr[r].first == m){
            cout << arr[l].second << ' ' << arr[r].second << '\n';
            return;
        }

        if(arr[l].first + arr[r].first > m){
            r--;
        }
        else{
            l++;
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
