#include <bits/stdc++.h>
#define int long long
using namespace std;

void func(int n){
    if(n == 1) return;
    if(n%2){
        n*=3;
        n+=1;
        cout << n << ' ';
        func(n);
    }
    else{
        n/=2;
        cout << n << ' ';
        func(n);
    }
}

void solve(){
    int n;
    cin >> n;

    cout << n << ' ';

    func(n);

}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
