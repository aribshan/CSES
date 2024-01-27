#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));

    for(int i=0; i<n; i++){
        cin >> arr[i][0];
        arr[i][1] = i;
    }

    sort(arr.begin(), arr.end());

    int count = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i][1] > arr[i+1][1]){
            count++;
        }
    }

    count++;

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
