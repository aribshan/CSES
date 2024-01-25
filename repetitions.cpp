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

    int l = 0, r =0;

    int maxCount = 0;

    while(r<n){
        if(s[r] != s[l]){
            maxCount = max(maxCount, r-l);
            l = r;
        }
        else{
            r++;
        }
    }
    maxCount = max(maxCount, r-l);

    cout << maxCount << '\n';

    return 0;
}
