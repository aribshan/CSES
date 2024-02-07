#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree;
vector<int> arr;
vector<int> lazy;

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
}

void update(int idx, int l, int r, int lq, int rq, int k){
    if(l>rq || r<lq) return;
    if(l>=lq && r<=rq){
        lazy[idx] += k;
        return;
    }
    int mid = (l+r)/2;
    update(2*idx, l, mid, lq, rq, k);
    update(2*idx+1, mid+1, r, lq, rq, k);
}

int query(int idx, int l, int r, int pos){
    if(l>pos || r<pos) return 0;
    if(l == r){
        return tree[idx]+lazy[idx];
    }
    int mid = (l+r)/2;
    if(lazy[idx]){
        lazy[2*idx] += lazy[idx];
        lazy[2*idx+1] += lazy[idx];
        lazy[idx] = 0;
    }
    return query(2*idx, l, mid, pos)+query(2*idx+1, mid+1, r, pos);

}

void solve(){
    tree.clear();
    arr.clear();
    lazy.clear();

    int n, q;
    cin >> n >> q;

    tree.resize(4*n);
    lazy.resize(4*n, 0);

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    build(1, 0, n-1);
    // for(int i=0; i<2*n; i++){
    //     cout << i <<' ' << tree[i] << '\n';
    // }
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int l, r, val;
            cin >> l >> r >> val;

            update(1, 0, n-1, l-1, r-1, val);
        }
        else{
            int k;
            cin >> k;

            int ans = query(1, 0, n-1, k-1);
            cout << ans << '\n';
        }
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

