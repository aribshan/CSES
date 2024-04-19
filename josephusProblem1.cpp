#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> next(n+2);
    vector<int> prev(n+2);

    for(int i=1; i<=n-1; i++){
        next[i] = i+1;
        prev[i+1] = i;
    }
    next[n] = 1;
    prev[1] = n;

    int curr = 2;
    if(n == 1) curr = 1;
    for(int i=0; i<n; i++){
        cout << curr << ' ';
        next[prev[curr]] = next[curr];
        prev[next[curr]] = prev[curr];
        curr = next[next[curr]];
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