#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_VAL = 1e6;
int freq[MAX_VAL + 1];

void solve(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        freq[a]++;
    }

    for(int i=MAX_VAL; i>0; i--){
        int vals = 0;

        for(int j=i; j<=MAX_VAL; j+=i){
            vals += freq[j];
        }
        if(vals > 1){
            cout << i << '\n';
            return;
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

