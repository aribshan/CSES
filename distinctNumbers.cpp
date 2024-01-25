#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    set<int> st;

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        st.insert(val);
    }

    cout << st.size() << '\n';
}

//1-9 = 1 -> 9
//10- 99 = 2 -> 90*2 = 180
//100 - 999 = 3 -> 900*3 = 2700
//1000 - 9999 = 4

 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
