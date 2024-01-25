#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n), brr(m);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<m; i++){
        cin >> brr[i];
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    int count = 0;
    int i = 0, j = 0;
    while(i<n && j<m){
        if(arr[i]-k > brr[j]){
            j++;
        }
        else if(arr[i]+k < brr[j]){
            i++;
        }
        else{
            count++;
            i++;
            j++;
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
