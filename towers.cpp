#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    //vector<vector<int>> brr(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> arr[i];
        // brr[i][0] =arr[i];
        // brr[i][1] = i;
    }

    multiset<int> st;
    for(int i=0; i<n; i++){
        auto it = st.upper_bound(arr[i]);
        if(it == st.end()){
            st.insert(arr[i]);
        }
        else{
            int val = *it;
            st.erase(st.find(val));
            st.insert(arr[i]);
        }
    }

    cout << st.size() << '\n';

    // sort(brr.begin(), brr.end(), [&](vector<int>&a, vector<int>&b){
    //     if(a[0] == b[0]) return a[1] < b[1];
    //     return a[0] > b[0];
    // });

    // for(int i=0; i<n; i++){
    //     cout << brr[i][0] << ' ' << brr[i][1] << '\n';
    // }

    // int count = 1;
    // for(int i=0; i<n-1; i++){
    //     if(brr[i][1] > brr[i+1][1]){
    //         count++;
    //     }
    // }

    //cout << count << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
