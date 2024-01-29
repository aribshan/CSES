#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> parent;
int findPar(int x){
    if(parent[x] == x) return x;
    return parent[x] = findPar(parent[x]);
}

void merge(int x, int y){
    int xx = findPar(x);
    int yy = findPar(y);

    if(xx != yy){
        parent[xx] = yy;
        parent[x] = yy;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        merge(a,b);
    }

    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(findPar(i) == i){
            ans.push_back(i);
        }
    }

    if(ans.size() > 1){
        cout << (ans.size()-1) << '\n';
        for(int i=0; i<ans.size()-1; i++){
            cout << ans[i] << ' ' << ans[i+1] << '\n';
        }
    }
    else{
        cout << 0 << '\n';
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
