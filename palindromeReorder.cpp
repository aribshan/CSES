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

    int mask = 0;
    for(auto ch : s){
        mask ^= (1<<(ch-'A'));
    }

    if(__builtin_popcount(mask) >= 2){
        cout << "NO SOLUTION" << '\n';
    }
    else{
        vector<int> mp(26, 0);
        for(auto ch : s){
            mp[ch-'A']++;
        }
        string ans = "";
        string mid = "";

        for(int i=0; i<26; i++){
            if(mp[i]%2 != 0){
                for(int j=0; j<mp[i]; j++){
                    mid += 'A'+i;
                }
            }
            else{
                for(int j=0; j<mp[i]/2; j++){
                    ans += ('A'+i);
                } 
            }
        }

        string rev = ans;
        reverse(rev.begin(), rev.end());

        cout << ans << mid << rev << '\n';

    }

    return 0;
}
