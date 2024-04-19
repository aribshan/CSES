#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;

vector<vector<int>> temp;
void square(vector<vector<int>>& arr){
    temp = arr;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            arr[i][j] = 0;
            for(int k=0; k<2; k++){
                arr[i][j] += temp[k][i] * temp[j][k];
                arr[i][j] %= MOD;
            }
        }
    }
}

void multiply(vector<vector<int>> & ans, vector<vector<int>> & arr){
    temp = ans;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            ans[i][j] = 0;
            for(int k=0; k<2; k++){
                ans[i][j] += temp[k][i] * arr[j][k];
                ans[i][j] %= MOD;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;

    if(n == 0){
        cout << 0 << '\n';
        return;
    }
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    n -= 2;

    vector<vector<int>> arr = {{1, 1}, {1, 0}};
    vector<vector<int>> ans = {{1, 0}, {0, 1}};

    for(int i=0; i<=60; i++){
        if(n & (1ll << i)) multiply(ans, arr);
        square(arr);
    }

    cout << (ans[0][1] + ans[0][0]) % MOD << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}