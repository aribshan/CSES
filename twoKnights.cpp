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
 
    int k;
    cin >> k;

    for(int i=1; i<=k; i++){
        int tot = (i*i*(i*i-1));
        int red = 0;

        if(i>2) red += 2*4;
        if(i == 3) red += 2*4;
        if(i > 3) {
            red += 3*2*4;
            red += 4*4;
        }
        if(i>4){ 
            red += 4*(i-4)*6;
            red += 8*((i-4)*(i-4));
            red += 4*(i-4)*4;
        }

        cout << (tot - red)/2 << '\n';
    }

    return 0;
}
