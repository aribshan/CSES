#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree;
vector<int> arr;

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;

    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = min(tree[2*idx], tree[2*idx+1]);
}

int query(int idx, int l, int r, int lq, int rq){
    if(l>rq || r<lq) return 1e9+1;
    if(l>=lq && r<=rq){
        return tree[idx];
    }

    int mid = (l+r)/2;
    return min(query(2*idx, l, mid, lq, rq), query(2*idx+1, mid+1, r, lq, rq));
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    tree.resize(4*n, 1e9);
    build(1, 0, n-1);

    while(q--){
        int a, b;
        cin >> a >> b;

        int ans = query(1, 0, n-1, a-1, b-1);
        cout << ans << '\n';
    }

    //cout << "DONE" << '\n';
}
 
signed main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);  
#endif
 
    solve();

    return 0;
}

