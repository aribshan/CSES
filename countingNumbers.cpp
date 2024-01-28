#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[20][2][2][2][11];
string as, bs;
int len;

int rec(int idx, int ul, int ll, int nz, int prev){
    if(idx >= len) return 1;
    if(dp[idx][ul][ll][nz][prev] != -1) return dp[idx][ul][ll][nz][prev];

    int ub = ul ? bs[idx]-'0' : 9;
    int lb = ll ? as[idx]-'0' : 0;

    // cout << idx << ' ' << ul << ' ' << ll << ' ' << nz << ' ' << prev << '\n';
    // cout << ub << ' ' << lb << '\n';
    int ans = 0;
    for(int i=lb; i<=ub; i++){
        if(i == prev) continue;

        //ans += rec(idx+1, (ul&&(i==ub)), (ll&&(i==lb)), nz, i);

        if(i == 0){
            if(nz){
                ans += rec(idx+1, (ul&&(i==ub)), (ll&&(i==lb)), nz, i);
            }
            else{
                ans += rec(idx+1, (ul&&(i==ub)), (ll&&(i==lb)), nz, prev);
            }
        }
        else{
            ans += rec(idx+1, (ul&&(i==ub)), (ll&&(i==lb)), nz, i);
        }     
    }

    return dp[idx][ul][ll][nz][prev] = ans;
}

void solve(){
    int a, b;
    cin >> a >> b;

    as = to_string(a);
    bs = to_string(b);

    int leftover = bs.length() - as.length();
    string temp;
    for(int i=0; i<leftover; i++){
        temp += '0';
    }

    memset(dp, -1, sizeof(dp));
    as = temp+as;
    len = bs.length();

    int ans = rec(0, 1, 1, 0, 10);
    if((a == 0 || a == 1) && (a!=b)) ans--;

    //cout << as << ' ' << bs << ' ';

    cout << ans << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
