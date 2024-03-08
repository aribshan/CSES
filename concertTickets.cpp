#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    multiset<int> st;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        st.insert(a);
    }

    for(int i=0; i<q; i++){
        int val;
        cin >> val;
        auto it = st.upper_bound(val);
        if(it == st.begin()){
            cout << -1 << '\n';
        }
        else{
            it--;
            cout << *it << '\n';
            st.erase(it);
        }
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

