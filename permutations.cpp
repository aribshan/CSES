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

    vector<int> arr(n, 0);

    if(n == 1){
        cout << 1 << '\n';
        return 0;
    }
    if(n == 2 || n == 3){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    int val = (n+1)/2;
    for(int i=0; i<n; i+=2){
        arr[i] = val;
        val--;
    }
    val = n;
    for(int i=1; i<n; i+=2){
        arr[i] = val;
        val--;
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
     cout << '\n';



    return 0;
}
