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
 
    int n;
    cin >> n;

    int twos = 0;
    int fives = 0;

    int two = 2, five = 5;
    while(n/two){
        twos += (n/two);
        two *= 2;
    }
    while(n/five){
        fives += (n/five);
        five *= 5;
    }

    cout << min(twos, fives) << '\n';

    return 0;
}
