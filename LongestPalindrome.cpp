#include <bits/stdc++.h>
#define int long long
using namespace std;

struct manacher{
    vector<int> p;

    void run_manacher(string s){
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;

        for(int i=1; i<n; i++){
            p[i] = max(0ll, min(r - i, p[l + r - i]));

            while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]){
                p[i]++;
            }

            if(i + p[i] > r){
                l = i - p[i];
                r = i + p[i];
            }
        }

        // for(auto v : p){
        //     cout << v << ' ';
        // }
        // cout << '\n';
    }

    void build(string s){
        string t;

        for(auto v : s){
            t += string("#") + v;
        }
        run_manacher(t + "#");
    }

    int getLongest(int cen, bool odd){
        int pos = 2 * cen + 1 + (!odd);
        return p[pos] - 1;
    }

    bool check(int l, int r){
        if(r-l+1 <= getLongest((l+r)/2, l%2==r%2)){
            return true;
        }
        return false;
    }
}m;

void solve(){
    string s;
    cin >> s;

    m.build(s);
    int mx = 0, idx = 0;
    for(int i=0; i<s.length(); i++){
        int val = m.getLongest(i, 1);
        if(val > mx){
            idx = i;
            mx = val;
        }
        val = m.getLongest(i, 0);
        if(val > mx){
            idx = i;
            mx = val;
        }
    }

    // cout << idx << ' ' << mx << '\n';
    cout << s.substr((idx - (mx - 1) / 2), mx) << '\n';
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