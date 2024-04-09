#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void solve(){
    ull n, m;
    cin >> n >> m;

    ull arr[m];
    for(int i=0; i<m; i++){
        cin >> arr[i];
    }

    ull ans = 0;
    ull ansd = 0;

    for(int i=1; i<(1<<m); i++){
        ull val = 1;

        bool ok = true;
        for(int j=0; j<m; j++){
            if(i & (1 << j)){
                ull newval = val * arr[j];
                if(newval / arr[j] != val || newval > n){
                    ok = false;
                    break;
                }
                val = newval;
            }
        }

        if(!ok){
            continue;
        }

        int cnt = __builtin_popcount(i);
        if(cnt % 2){
            ans += (n / val);
        }
        else{
            ansd += (n / val);
        }
    }

    cout << ans - ansd << '\n';
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