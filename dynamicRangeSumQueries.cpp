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
    tree[idx] = (tree[2*idx] + tree[2*idx+1]);
}

void update(int idx, int l, int r, int pos){
    if(l>pos || r<pos) return;

    if(l == r){
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;

    update(2*idx,  l, mid, pos);
    update(2*idx+1, mid+1, r, pos);
    tree[idx] = (tree[2*idx] + tree[2*idx+1]);
}

int query(int idx, int l, int r, int lq, int rq){
    if(l>rq || r<lq) return 0;
    if(l>=lq && r<=rq){
        return tree[idx];
    }

    int mid = (l+r)/2;
    return (query(2*idx, l, mid, lq, rq) + query(2*idx+1, mid+1, r, lq, rq));
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
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            arr[b-1] = c;
            update(1, 0, n-1, b-1);
        }
        else{
            int ans = query(1, 0, n-1, b-1, c-1);
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

