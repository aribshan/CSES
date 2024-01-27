#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    stack<int> st;

    vector<int> ans(n, 0);

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
            ans[st.top()] = i+1;
            st.pop();
        }
        st.push(i);
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
