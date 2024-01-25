#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    string s;
    cin >> s;

    int n = s.length();

    set<string> st;
    int times = 1;
    while(n){
        times *= n;
        n--;
    }

    //cout << times << ' ';

    for(int i=0; i<=times; i++){
        next_permutation(s.begin(), s.end());
        st.insert(s);
    }

    cout << st.size() << '\n';

    for(auto x : st){
        cout << x << '\n';
    }

    return 0;
}
