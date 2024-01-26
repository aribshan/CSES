#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<vector<int>> arr(n, vector<int>(2));

    for(int i=0; i<n; i++){
        cin >> arr[i][0];
        arr[i][1] = i+1;
    }

    sort(arr.begin(), arr.end());

    int a = -1, b = -1, c = -1;

    for(int i=0; i<n; i++){
        int val = arr[i][0];
        int l = i+1, r = n-1;
        while(l<r){
            //cout << val << ' ' << arr[l][0] << ' ' << arr[r][0] << '\n';
            if(val + arr[l][0] + arr[r][0] == x){
                a = arr[i][1], b = arr[l][1], c = arr[r][1];
                l = r+1;
                break;
            }

            if(val + arr[l][0] + arr[r][0] > x){
                r--;
            }
            else if(val + arr[l][0] + arr[r][0] < x){
                l++;
            }
        }
    }

    if(a == -1){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        cout << a << ' ' << b << ' ' << c << '\n';
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
