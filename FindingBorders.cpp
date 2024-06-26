#include <bits/stdc++.h>
#define int long long
using namespace std;

int MAX = 1e6+5;

void calculate_ZFunction(int *z, string s) {
    int N = (int)s.size();
    int l = 0;
    int r = 0;
    for (int i = 0; i < N; i ++) z[i] = 0;
    for (int i = 1; i < N; i ++) {
        if (r >= i) z[i] = min(z[i - l], r - i + 1);
        while (z[i] + i < N && s[z[i]] == s[z[i] + i]) z[i] ++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

void solve(){
    string s;
    cin >> s;

    int n = s.length();
    int z[n];
    calculate_ZFunction(z, s);

    vector<int> ans;
    for(int i=0; i<n; i++){
        if(z[i] == (n - i)) ans.push_back(n-i);
    }

    reverse(ans.begin(),ans.end());
    for(int x : ans){
        cout << x << ' ';
    }
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