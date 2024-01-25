#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> ans = {0,1};

    for(int i=1; i<n; i++){
        int m = ans.size();
        for(int j=m-1; j>=0; j--){
            int val = ((1<<i)|(ans[j]));
            ans.push_back(val);
        }
    }

    for(auto x : ans){
        string bin = "";
        int val = x;
        while(val){
            if(val%2){
                bin += '1';
            }
            else{
                bin += '0';
            }
            val/=2;
        }
        reverse(bin.begin(), bin.end());
        int m = bin.size();
        string temp = "";
        while(n-m){
            temp += '0';
            m++;
        }
        cout << temp << bin << '\n';
        

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
