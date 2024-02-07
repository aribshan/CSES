#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i-1][j-1] == '*'){
                prefix[i][j] = 1+prefix[i][j-1];
            }
            else{
                prefix[i][j] = prefix[i][j-1];
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            prefix[i][j] += prefix[i-1][j];
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++){
    //         cout<<prefix[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    while(m--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int ans = prefix[c][d] + prefix[a-1][b-1];
        ans -= prefix[a-1][d];
        ans -= prefix[c][b-1];

        cout << ans << '\n';
    }
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}

