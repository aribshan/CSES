#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> parent, r;
int mx, comps;

int findPar(int a){
    if(parent[a] == a) return a;
    return parent[a] = findPar(parent[a]);
}

void merge(int a, int b){
    int aa = findPar(a);
    int bb = findPar(b);

    if(aa != bb){
        comps--;
        if(r[aa] >= r[bb]){
            r[aa] += r[bb];
            mx = max(mx, r[aa]);
            parent[bb] = aa;
            parent[b] = aa;
        }
        else{
            r[bb] += r[aa];
            mx = max(mx, r[bb]);
            parent[aa] = bb;
            parent[a] = bb;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    comps = n, mx = 1;

    parent.resize(n+1);
    r.resize(n+1, 1);
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        merge(a, b);
        cout << comps << ' ' << mx << '\n';
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

