#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;

    int sum = (n*(n+1))/2;

    if(sum%2){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';

    vector<int> a, b;
    int target = sum/2;

    int i = n;
    while(target){
        if(i>target){
            i = target;
        }
        a.push_back(i);
        target -= i;
        i--;
    }

    sort(a.begin(), a.end());

    i = 0;
    for(int j=1; j<=n; j++){
        if(i<n && j == a[i]){
            i++;
        }
        else{
            b.push_back(j);
        }
    }

    cout<<a.size() << '\n';
    for(auto x : a){
        cout << x << ' ';
    }
    cout << '\n';

    cout << b.size() << '\n';
    for(auto x : b){
        cout << x << ' ';
    }
    cout << '\n';

    return;
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}
