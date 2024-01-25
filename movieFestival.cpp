#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> mov(n, vector<int>(2));

    for(int i=0; i<n; i++){
        cin >> mov[i][0] >> mov[i][1];
    }

    sort(mov.begin(), mov.end(), [&](vector<int>&a, vector<int>&b){
        if(a[1] == b[1]){
            return a[0] > b[0];
        }
        return a[1] < b[1];
    });

    int count = 0;
    int prev = 0;

    int i = 0;
    while(i<n){
        if(mov[i][0] >= prev){
            count++;
            prev = mov[i][1];
        }
        i++;
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
