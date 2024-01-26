#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }

    multiset<int> st;

    int l = 0, r = 0, mx = 0;

    while(r < n){
        if(st.find(arr[r]) != st.end()){    
            st.erase(st.find(arr[l]));
            l++;
        }
        else{
            st.insert(arr[r]);
            mx = max(mx, (int)st.size());
            r++;
        }
    }

    cout << mx << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
